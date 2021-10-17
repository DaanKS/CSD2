import simpleaudio as sa
import time
import random

#___________setup___________
#load Samples to variables
kick="kick"
mid="mid"
tom="tom"

instruments = [kick, mid, tom]
#event creation
def make_event(timeStamp, instrument):
    return {'timeStamp':timeStamp,'instrument':instrument}
#event handling
def play(event):
    print(event['instrument'])

#user input
    #bpm
BPM = int(input("Enter BPM (int): "))
sixTeenthStep = (60 / BPM) / 4
    #maatsoort
topMaat = int(input("Top Maat: "))
botMaat = int(input("Bot Maat: "))
        #maatsoort to grid that can be filled by user
#formula to work out amount of sixteenthNotes there are in the entered
if botMaat == 4:
    amountSixTeenthNote = topMaat * 4
elif botMaat == 8:
    amountSixTeenthNote = topMaat * 2
elif botMaat == 16:
    amountSixTeenthNote = topMaat
elif botMaat == 32:
    amountSixTeenthNote = topMaat / 2
elif botMaat == 2:
    amountSixTeenthNote = topMaat * 8
else:
    amountSixTeenthNote = 1
    print("Maatsoort Error - Maatsoort now: ", topMaat, " / 1 ")

#list of all sixteenth steps
allSteps = [0]
for i in range(amountSixTeenthNote):
    allSteps.append(i * sixTeenthStep)
allSteps.pop() #remove the last step
#enter percentage per step
kickPercentage=[]
for i in range(amountSixTeenthNote):
    print ("Kick step ", i + 1)
    kickPercentage.append(int(input("Chance 0 - 100: ")))
tomPercentage=[]
for i in range(amountSixTeenthNote):
    print ("Tom step ", i + 1)
    tomPercentage.append(int(input("Chance 0 - 100: ")))
midPercentage=[]
for i in range(amountSixTeenthNote):
    print ("Mid step ", i + 1)
    midPercentage.append(int(input("Chance 0 - 100: ")))


events = []
#turn percentages into timestamps and events
for i in range(amountSixTeenthNote):
        if random.randint(0, 101) >= kickPercentage[i]:
            events.append(make_event(allSteps[i], kick))
        if random.randint(0, 101) >= tomPercentage[i]:
            events.append(make_event(allSteps[i], tom))
        if random.randint(0, 101) >= midPercentage[i]:
            events.append(make_event(allSteps[i], mid))
#line provided by Wouter Ensink - quick sorting algorhithm
events.sort(key=lambda x: x['timeStamp'])
#this list of events will be used to export midi, but not for playback

    #counter with repeats
for repeats in range(4): #could be replaced by a while loop for infinite repeats
        #counter
    time_zero = time.time()
        #amount of steps
    for index in range(amountSixTeenthNote):
        print(index)

            #on button for while loop
        running = True
            #targetTime is where the next hit should be. We use the sixTeenths[]
        targetTime = allSteps[index]
        while running:
                #what is the time now
            currentTime = time.time() - time_zero
                #has the clock hit the targetTime?
            if currentTime >= targetTime:
                for event in events:
                    if event['timeStamp'] == allSteps[index]:
                            play(event)
                    #turn off the while loop to go to the next step
                running = False
            else:
                time.sleep(0.001)
