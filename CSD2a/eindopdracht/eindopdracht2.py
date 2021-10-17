import simpleaudio as sa
import time
import random

#___________setup___________

kick = "kick"
mid = "mid"
tom = "tom"
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
def play(event):
    print(event['instrument'])

#ChangeBPM
def changeBPM():
    BPM = float(input("Enter BPM: "))
    sixTeenthStep = (60 / BPM) / 4
#change maatsoort
def changeMaat():
    topMaat = int(input("Enter topMaat: "))
    botMaat = int(input("Enter botMaat: "))
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

    for i in range(amountSixTeenthNote):
        allSteps.append(i * sixTeethStep)
    allSteps.pop() #remove the last step

#fill in percentages
def fillKick():
    for i in range(amountSixTeenthNote):
        print ("Kick step ", i + 1)
        kickPercentage.append(int(input("Chance 0 - 100: ")))
def fillTom():
    for i in range(amountSixTeenthNote):
        print ("Tom step ", i + 1)
        tomPercentage.append(int(input("Chance 0 - 100: ")))
def fillMid():
    for i in range(amountSixTeenthNote):
        print ("Mid step ", i + 1)
        midPercentage.append(int(input("Chance 0 - 100: ")))

#reroll events
def reRollAll():
    for i in range(amountSixTeenthNote):
            if random.randint(0, 101) >= kickPercentage[i]:
                events.append(make_event(allSteps[i], kick))
            if random.randint(0, 101) >= tomPercentage[i]:
                events.append(make_event(allSteps[i], tom))
            if random.randint(0, 101) >= midPercentage[i]:
                events.append(make_event(allSteps[i], mid))
#reroll events seperately
def reRollKick():
    for i in range(amountSixTeenthNote):
        if random.randint(0, 101) >= kickPercentage[i]:
            events.append(make_event(allSteps[i], kick))
def reRollTom():
    for i in range(amountSixTeenthNote):
        if random.randint(0, 101) >= tomPercentage[i]:
            events.append(make_event(allSteps[i], tom))
def reRollMid():
    for i in range(amountSixTeenthNote):
        if random.randint(0, 101) >= midPercentage[i]:
            events.append(make_event(allSteps[i], mid))
