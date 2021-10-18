import simpleaudio as sa
import time
import random

#___________setup___________

kick = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Kick_bip.wav")
mid = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Mid_bip.wav")
tom = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Tom_bip.wav")
instruments = [kick, mid, tom]

BPM = 120

allSteps = [0]
topMaat = 4
botMaat = 4

kickPercentage=[]
tomPercentage=[]
midPercentage=[]

events=[]

#__________methods___________

#making events
def make_event(timeStamp, instrument):
    return {'timeStamp' : timeStamp, 'instrument':instrument}
#playing events
def playEvent(event):
    event['instrument'].play()
    print(event['instrument'])

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
        amountSixTeenthNote = 4
        print("Maatsoort Error - Maatsoort now: ", topMaat, " / 4 ")
    return amountSixTeenthNote
    #calculate the amount of steps per bpm
def calculateSteps(amountSixTeenthNote, sixTeenthStep):
    for i in range(amountSixTeenthNote):
        allSteps.append((i+1) * sixTeenthStep)
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

#__________running__________
print("Welcome")
peter = changeBPM()
greg = changeMaat(peter)
calculateSteps(greg, peter)
print("Fill in percenages")
fillKick(greg)
fillTom(greg)
fillMid(greg)
print("Calculating.")
time.sleep(1)
print("Calculating..")
time.sleep(1)
print("Calculating...")
reRollAll(greg)
time.sleep(0.5)
print("Ready To Play")
print(events)

#_________playing___________

for repeats in range(4): #could be replaced by a while loop for infinite repeats
        #counter
    time_zero = time.time()
        #amount of steps
    for index in range(greg):
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
                            playEvent(event)
                    #turn off the while loop to go to the next step
                running = False
            else:
                time.sleep(0.001)
