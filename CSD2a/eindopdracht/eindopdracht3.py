import simpleaudio as sa
import time
import random
from midiutil import MIDIFile

#___________setup___________

kick = {'instrument':"kick", 'instrumentName': "kick"}
mid = {'instrument':"mid",'instrumentName': "mid"}
tom = {'instrument':"tom", 'instrumentName': "tom"}
instruments = [kick, mid, tom]
instrumentMidiNums = [36, 40, 45]
instrumentNames = ["kick", "mid", "tom"]

BPM = 120

allSteps = []
topMaat = 4
botMaat = 4

kickPercentage=[]
tomPercentage=[]
midPercentage=[]

events=[]

#__________methods___________

#making events
def make_event(timeStamp, instrument, instrumentName):
    return {'timeStamp' : timeStamp, 'instrument':instrument, 'instrumentName': instrumentName}
#playing events
def playEvent(event):
    #event['instrument'].play()
    print(event['instrumentName'])

#ChangeBPM
def changeBPM():
    BPM = float(input("Enter BPM: "))
    sixTeenthStep = (60 / BPM) / 4
    return sixTeenthStep
#change maatsoort
def changeMaat(sixTeenthStep):
    topMaat = int(input("Enter topMaat: "))
    botMaat = int(input("Enter botMaat: "))
    #resetevents because it won't work anymore after redoing this.
    events = []
#checking if the botMaat makes sense
    amountSixTeenthNote = int(topMaat * (16 / botMaat))
    print(amountSixTeenthNote)
    return amountSixTeenthNote

    #calculate the amount of steps per bpm
def calculateSteps(amountSixTeenthNote, sixTeenthStep):
    for i in range(amountSixTeenthNote):
        allSteps.append(i * sixTeenthStep)
    allSteps.pop() #remove the last step

#fill in percentages
def fillKick(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
        print ("Kick step ", i + 1)
        kickPercentage.append(int(input("Chance 0 - 100: ")))
def fillTom(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
        print ("Tom step ", i + 1)
        tomPercentage.append(int(input("Chance 0 - 100: ")))
def fillMid(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
        print ("Mid step ", i + 1)
        midPercentage.append(int(input("Chance 0 - 100: ")))

#reroll events
def reRollAll(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
            if random.randint(0, 101) <= kickPercentage[i]:
                events.append(make_event(allSteps[i], kick))
            if random.randint(0, 101) <= tomPercentage[i]:
                events.append(make_event(allSteps[i], tom))
            if random.randint(0, 101) <= midPercentage[i]:
                events.append(make_event(allSteps[i], mid))
#reroll events seperately
def reRollKick(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
        if random.randint(0, 101) <= kickPercentage[i]:
            events.append(make_event(allSteps[i], kick))
def reRollTom(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
        if random.randint(0, 101) <= tomPercentage[i]:
            events.append(make_event(allSteps[i], tom))
def reRollMid(amountSixTeenthNote):
    for i in range(amountSixTeenthNote):
        if random.randint(0, 101) <= midPercentage[i]:
            events.append(make_event(allSteps[i], mid))
def sortEvents():
    events.sort(key=lambda x: x['timeStamp'])

#___________MIDI____________
midiFile = MIDIFile(1)
track = 0
time = 0
duration = 1
volume = 100
midiFile.addTrackName(track, time, "eindopdracht")
midiFile.addTempo(track, time, BPM)

#unpack event and turn into a midinote
def retrievePitch(event):
    for i in range(3):
        if event['instrumentName'] == instrumentNames[i]:
            return instrumentMidiNums[i]
def retrieveTime(event):
    return int(event['timeStamp'] /  lengthSixteenthNote)
def addMidiNote(pitch, time):
    midiFile.addNote(track, channel, pitch, time, duration, volume)

#__________running__________
print("Welcome")
lengthSixteenthNote = changeBPM()
numSixteenthNote = changeMaat(lengthSixteenthNote)
calculateSteps(numSixteenthNote, lengthSixteenthNote)
print("Fill in percenages")
fillKick(numSixteenthNote)
fillTom(numSixteenthNote)
fillMid(numSixteenthNote)
print("Calculating.")
time.sleep(1)
print("Calculating..")
time.sleep(1)
print("Calculating...")
reRollAll(numSixteenthNote)
sortEvents()
time.sleep(0.5)
print("Ready To Play")

#_________playing___________

for repeats in range(4): #could be replaced by a while loop for infinite repeats
    timeZero = time.time() #begin point for time
    for index in range(numSixteenthNote):  #amount of steps
        running = True  #on button for while loop
        while running:
            currentTime = time.time() - time_zero #what is the time now
            for event in events:
                #Look through every element of the events list:
                #It may seem arbitrary to look through the entire list, but for now
                #I am of the opinion that it is an effective method to loop a beat without
                #pop(). So I can just iterate through events instead of removing them.
                if event['timeStamp'] == currentTime:
                        playEvent(event)
                        running = False
            time.sleep(0.001)
