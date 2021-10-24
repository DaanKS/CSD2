import simpleaudio as sa
import time
import random
from midiutil import MIDIFile

#rhythm generation through simple lindenmayer system

#___________setup___________
kick = {'instrument':"kick", 'instrumentName': "kick"}
mid = {'instrument':"mid",'instrumentName': "mid"}
high = {'instrument':"high", 'instrumentName': "high"}
instruments = [kick, mid, tom]
instrumentMidiNums = [36, 40, 45]
instrumentNames = ["kick", "mid", "high"]
events = []
BPM = 120

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
def fillMidPercentage(numBeats):
    for step in range(numBeats):
        print ("Mid Step: ", step + 1)
        midPercentage.append(int(input("Chance 0-100: ")))

#calculate position of 16th note in time
def calculateSteps(numBeats, sixteenthStep):
    for i in range(numBeats):
        allSteps.append(i * sixteenthStep)
    allSteps.pop() #remove the last step

#using percentages to fill in events.
def reRollAll(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
            if random.randint(0, 101) <= kickPercentage[i]:
                events.append(make_event(allSteps[i], kick))
            if random.randint(0, 101) <= midPercentage[i]:
                events.append(make_event(allSteps[i], mid))
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


#___________running_____________
#I TOOK THIS CODE FROM /eindopdracht_snippets/11_index_instead_of_pop.py
#From Ciska Vriezenga, thanks Ciska :)

# check if events is not empty
if not events:
    # list contains no items
    exit()

# store the current time
time_zero = time.time()
print("time zero:", time_zero)
# start at index 0 and retrieve reference to current timestamp
index = 0
event = events[index]
ts = event["timestamp"]

# iterate through time sequence and play sample
while True:
    now = time.time() - time_zero
    # did we arrive at the new timestamp?
    if(now > ts):
        # play sample and fetch new event and timestamp
        samples[event["sample_index"]].play()
        if index >= len(events):
            event = events[index]
            ts = event["timestamp"]
        else:
            # NOTE: or, if you want to loop, you could repeat at index 0
            # and then add an time-offset for the current bar
            break

    time.sleep(0.001)
