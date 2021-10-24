import simpleaudio as sa
import time as ti
import random
from midiutil import MIDIFile

#rhythm generation through simple lindenmayer system

#___________setup___________
kick = {'instrument':"kick", 'instrumentName': "kick"}
mid = {'instrument':"mid",'instrumentName': "mid"}
high = {'instrument':"high", 'instrumentName': "high"}
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
#because lindenmayer systems work recursively we have to make it stop somewhere
#numGenerations is the depth of recursiveness.
numGenerations = 1
#1 = hit, 0 = rest.
#if 1 is given, send 1-0
# if 0 is given, send 1
rules = {1 : [1,0,0], 0 : [1,0,1] }
linden = [1]

#___________methods__________
#lindenmayer system
#to avoid infinite recursion, a for loop is used to limit the amount of generations
def spawnSystem(linden, numGeneration):
    for i in range(numGeneration):
        linden += lindenCompute(linden)
    linden.pop(0)
#applies the predetermined rules of the system
#checks last element of the system to decide what must come next.
def lindenCompute(linden):
    return rules[linden[len(linden) - 1]]

#event builder
def makeEvent(timeStamp, instrument, instrumentName):
    return {'timeStamp': timeStamp, 'instrument':instrument,'instrumentName':instrumentName}
#event handler
def playEvent(event):
    #event['instrument'].play
    print(event['instrumentName'])

def askUserBPM():
    BPM = float(input("Enter BPM: "))
    #calculate length of sixteenth note by converting to quarternote, and then dividing by 4.
    sixteenthStep = (60 / BPM) / 4
    return sixteenthStep

def askUserTimesig(sixteenthStep):
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
        allSteps.pop()


#using percentages to fill in events.
def reRollAll(amountSixTeenthNote, events, allSteps):
    for i in range(amountSixTeenthNote):
            if random.randint(0, 101) <= kickPercentage[i]:

                events.append(makeEvent(allSteps[i], kick, "kick"))
            if random.randint(0, 101) <= midPercentage[i]:
                events.append(makeEvent(allSteps[i], mid, "mid"))
def sortEvents(events):
    events.sort(key=lambda x: x['timeStamp'])

#___________MIDI____________
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

#___________userInput___________
print("Welcome ")
lengthSixteenthNote = askUserBPM()
print("lengthSixteenthNote: ", lengthSixteenthNote)
numBeatsPerBar = askUserTimesig(lengthSixteenthNote)
print("numBeatsPerBar: ", numBeatsPerBar)
fillKickPercentages(numBeatsPerBar)
fillMidPercentages(numBeatsPerBar)
#calculateSteps(numBeatsPerBar, lengthSixteenthNote, allSteps)

for i in range(numBeatsPerBar):
    allSteps.append(i * lengthSixteenthNote)


print(allSteps)
reRollAll(numBeatsPerBar, events, allSteps)
sortEvents(events)

#___________running_____________
for repeats in range(4): #could be replaced by a while loop for infinite repeats
    timeZero = ti.time() #begin point for time
     #amount of steps
    running = True  #on button for while loop
    while running:
        currentTime = ti.time() - timeZero #what is the time now
        for event in events:
            #Look through every element of the events list:
            #It may seem arbitrary to look through the entire list, but for now
            #I am of the opinion that it is an effective method to loop a beat without
            #pop(). So I can just iterate through events instead of removing them.
            if event['timeStamp'] == currentTime:
                    playEvent(event)

        ti.sleep(0.001)
