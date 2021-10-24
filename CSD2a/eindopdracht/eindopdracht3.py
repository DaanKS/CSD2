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

#using percentages to fill in events.
def reRollAll(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
            if random.randint(0, 101) <= kickPercentage[i]:
                events.append(make_event(allSteps[i], kick))
            if random.randint(0, 101) <= midPercentage[i]:
                events.append(make_event(allSteps[i], mid))
def sortEvents(events):
    events.sort(key=lambda x: x['timeStamp'])
