import simpleaudio as sa
import time as ti
import random
from midiutil import MIDIFile

#___________setup___________
kick = sa.WaveObject.from_wave_file("/Users/dean/Documents/samples/kick.wav")
mid = sa.WaveObject.from_wave_file("//Users/dean/Documents/samples/block.wav")
high = sa.WaveObject.from_wave_file("/Users/dean/Documents/samples/hat.wav")
instruments = [kick, mid, high]
events = []
allSteps = []
kickPercentage = []
midPercentage = []

#__________methods___________

#event builder
def makeEvent(timestamp, instrument, midiNote):
    return{'timestamp': timestamp, 'sample_index': instrument, 'midiNote', midiNote}

#event handler
def playEvent(event):
    instruments[event['sample_index']].play()

def askUserBPM():
    BPM = input("Enter BPM: ")
    while not BPM.isnumeric():
        print("Try a number")
        BPM = input("Enter BPM: ")
    #calculate length of sixteenth note by converting to quarternote, and then dividing by 4.
    sixteenthStep = (60.0 / float(BPM)) / 4.0
    return sixteenthStep

def askUserTimesig():
    numerator = input("Enter numerator: ")
    while not numerator.isnumeric():
        print("Try a number")
        numerator = input("Enter numerator: ")
    denominator = input("Enter denominator: ")
    while not denominator.isnumeric():
        print("Try a number")
        denominator = input("Enter denominator: ")
    #calculate the amount of beats per bar
    return int(int(numerator) * (16 / int(denominator)))

#calculate position of 16th note in time
def calculateSteps(numBeats, sixteenthStep, allSteps):
    for i in range(numBeats):
        allSteps.append((i * sixteenthStep))
    #allSteps.pop()

#because lindenmayer systems work recursively we have to make it stop somewhere
#numGenerations is the depth of recursiveness.
#"for ever element in the lsystem:
#1 = hit, 0 = rest.
#if 1 is given, send 1-0
# if 0 is given, send 1 " - A basic Lsystem
#https://understanding-recursion.readthedocs.io/en/latest/15%20L-System.html
#in the following lsystems: due to if statements no longer possible to avoid duplicate code.
#it was first done with a variable dictionary with rules. method was incorrect.
def spawnKicks(lsystem, numGenerations):
    for i in range(numGenerations):
        lsystem += kickCompute(lsystem)
    lsystem.pop(0)

def kickCompute(lsystem):
    temp = [0]
    for l in lsystem:
        if l == 100:
            temp += [100, 0, 25]
        elif l == 25:
            temp += [25, 0]
        else:
            temp += [0, 0, 100]
    return temp

def spawnMids(lsystem, numGenerations):
    for i in range(numGenerations):
        lsystem += midCompute(lsystem)
    lsystem.pop(0)

def midCompute(lsystem):
    temp = [0]
    for l in lsystem:
        if l == 75:
            temp += [75, 75, 25]
        else:
            temp += [25, 75]
    return temp

def spawnHighs(lsystem, numGenerations):
    for i in range(numGenerations):
        lsystem += highCompute(lsystem)
    lsystem.pop(0)

def highCompute(lsystem):
    temp = [0]
    for l in lsystem:
        if l == 100:
            temp += [100, 50, 50]
        elif l == 50
            temp += [50, 75, 25, 25]
        elif l == 25:
            temp += [25, 75]
        else:
            temp += [75, 25, 100]
    return temp

#calculate the probability and place it in events
def rollProbabilities(numBeats, lsystem, instrument, midiNote):
    for i in range(numBeats):
            if random.randint(0, 101) <= lsystem[i]:
                events.append(makeEvent(allSteps[i],instrument, midiNote))

#sort events
def sortEvents(events):
    events.sort(key=lambda x: x['timeStamp'])

#run sequencer
def runSequencer():
    # check if events is not empty
    if not events:
        # list contains no items
        exit()

    # store the current time
    time_zero = ti.time()
    print("time zero:", time_zero)
    # start at index 0 and retrieve reference to current timestamp
    index = 0
    event = events[index]
    ts = event["timestamp"]

    # iterate through time sequence and play sample
    while True:
        now = ti.time() - time_zero
        # did we arrive at the new timestamp?
        if(now > ts):
            # play sample and fetch new event and timestamp
            playEvent(event)
            if index >= len(events):
                event = events[index]
                ts = event["timestamp"]
                index += 1
            else:
                # NOTE: or, if you want to loop, you could repeat at index 0
                # and then add an time-offset for the current bar
                break

        ti.sleep(0.001)

#___________MIDISETUP____________
midiFile = MIDIFile(1)
track = 0
time = 0
channel = 0
duration = 1
volume = 100
midiFile.addTrackName(track, time, "eindopdracht")
midiFile.addTempo(track, time, BPM)

def retrievePitch(event):
            return event['midiNote']

def retrieveTime(event, sixteenthStep):
    return int(event['timeStamp'] / sixteenthStep)

def addMidiNote(pitch, time):
    midiFile.addNote(track, channel, pitch, time, duration, volume)
