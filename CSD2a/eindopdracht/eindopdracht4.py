import simpleaudio as sa
import time as ti
import random
from midiutil import MIDIFile

#___________setup___________
kick = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Kick_bip.wav")
mid = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Mid_bip.wav")
high = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Tom_bip.wav")
instruments = [kick, mid, high]
instrumentMidiNums = [36, 40, 45]
instrumentNames = ["kick", "mid", "high"]

events = []
BPM = 120
allSteps = []
#make use of time_signature to conform to assignment
numerator =  4
denominator = 4

kickPercentage = []
midPercentage = []


#___________lindenmayerSystem_____________
#because lindenmayer systems work recursively we have to make it stop somewhere
#numGenerations is the depth of recursiveness.
numGenerations = 1
#1 = hit, 0 = rest.
#if 1 is given, send 1-0
# if 0 is given, send 1
rules = {1 : [1,0,0], 0 : [1,0,1,1] }
linden = [1]

#lindenmethods
#to avoid infinite recursion, a for loop is used to limit the amount of generations
def spawnSystem(linden, numGeneration):
    for i in range(numGeneration):
        linden += lindenCompute(linden)
    linden.pop(0)
#applies the predetermined rules of the system
#checks last element of the system to decide what must come next.
def lindenCompute(linden):
    return rules[linden[len(linden) - 1]]
#add lindenmayer rhythm to events
def lindenToEvents(numBeats):
    for i in range(numBeats):
        if linden[i % len(linden)] == 1:
            events.append(makeEvent(allSteps[i], high, 45))

#___________methods____________
#event builder
def makeEvent(timeStamp, instrument, midiNote):
    return{'timeStamp': timeStamp, 'instrument': instrument, 'midiNote': midiNote}
#event handler
def playEvent(event):
    event['instrument'].play()
    #print(event['instrument'])

def askUserBPM():
    BPM = float(input("Enter BPM: "))
    #calculate length of sixteenth note by converting to quarternote, and then dividing by 4.
    sixteenthStep = (60 / BPM) / 4
    return sixteenthStep

def askUserTimesig():
    numerator = int(input("Enter numerator: "))
    denominator = int(input("Enter denominator: "))
    #calculate the amount of beats per bar
    return int(numerator * (16 / denominator))

#TODO refactorize duplicate code
def fillKickPercentages(numBeats):
    for step in range(numBeats):
        print ("Kick Step: ", step + 1)
        kickPercentage.append(int(input("Chance 0-100: ")))
def fillMidPercentages(numBeats):
    for step in range(numBeats):
        print ("Mid Step: ", step + 1)
        midPercentage.append(int(input("Chance 0-100: ")))

#calculate position of 16th note in time
def calculateSteps(numBeats, sixteenthStep, allSteps):
    for i in range(numBeats):
        allSteps.append((i * sixteenthStep))
    #allSteps.pop()

#using percentages to fill in events.
def reRollAll(amountSixTeenthNote, events, allSteps):
    for i in range(amountSixTeenthNote):
            if random.randint(0, 101) <= kickPercentage[i]:

                events.append(makeEvent(allSteps[i], kick, 36))
            if random.randint(0, 101) <= midPercentage[i]:
                events.append(makeEvent(allSteps[i], mid, 40))
def sortEvents(events):
    events.sort(key=lambda x: x['timeStamp'])

def running():
    for repeats in range(2): #could be replaced by a while loop for infinite repeats
            #counter
        time_zero = ti.time()
            #amount of steps
        for index in range(numBeatsPerBar):
                #on button for while loop
            running = True
                #targetTime is where the next hit should be. We use the sixTeenths[]
            targetTime = allSteps[index]
            while running:
                    #what is the time now
                currentTime = ti.time() - time_zero
                    #has the clock hit the targetTime?
                if currentTime >= targetTime:
                    for event in events:
                        if event['timeStamp'] == allSteps[index]:
                                playEvent(event)
                        #turn off the while loop to go to the next step
                    running = False
                else:
                    ti.sleep(0.001)


#___________MIDISETUP____________
midiFile = MIDIFile(1)
track = 0
time = 0
duration = 1
volume = 100
midiFile.addTrackName(track, time, "eindopdracht")
midiFile.addTempo(track, time, BPM)

def retrievePitch(event, instrumentNames):
    for i in range(3):
        if event['instrumentName'] == instrumentNames[i]:
            return i

def retrieveTime(event, sixteenthStep):
    return int(event['timeStamp'] / sixteenthStep)

def addMidiNote(pitch, time):
    midiFile.addNote(track, channel, pitch, time, duration, volume)

#___________running_____________

print("welcome!")
beatLength = askUserBPM()
numBeatsPerBar = askUserTimesig()
calculateSteps(numBeatsPerBar, beatLength, allSteps)

#start with building lindenmayer system
print("Lindenmayer!")
linden=[int(input("Pick One: 0 or 1? "))]
generations = int(input("A number between 1 and 100: "))
spawnSystem(linden, generations)
print("Lindenmayer Rhythm: ", linden)
lindenToEvents(numBeatsPerBar)

#percentagebased section
fillKickPercentages(numBeatsPerBar)
fillMidPercentages(numBeatsPerBar)

reRollAll(numBeatsPerBar, events, allSteps)
sortEvents(events)

running()
