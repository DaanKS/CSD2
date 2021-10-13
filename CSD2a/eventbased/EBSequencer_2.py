import simpleaudio as sa
import time
import random

#loading up samples
#using strings for now to emulate use of simpleaudio
kick = "kick"#sa.WaveObject.from_wave_file("../Samples/Kick_bip.wav")
mid = "mid"#sa.WaveObject.from_wave_file("../Samples/Mid_bip.wav")
tom = "tom"#sa.WaveObject.from_wave_file("../Samples/Tom_bip.wav")

def play(event):
    print(event['instrument'])

bpm = 120
quarterNote = 60 / bpm
instruments = [kick, mid, tom]
timeStamps = []

def make_event(timestamp, instrument):
    return {'timeStamp': timestamp, 'instrument' : instrument}
events = []

#turn theGroove (durations) into timeStamps
theGroove=[1, 1, 1, 1]
timeLength = 0
for notes in theGroove:
    timeLength += notes
    timeStamps.append(timeLength)
#remove extraneous timestamp
timeStamps.pop()
count = 0

for i in range(len(timeStamps)):
    events.append(make_event(timeStamps[count], instruments[random.randint(0, 1)]))
    count += 1
#fill in 16th notes
for sixteenthNote in range(16):
    events.append(make_event(sixteenthNote * 0.25, instruments[2]))

#Took this line from Wouter Ensink
events.sort(key=lambda x: x['timeStamp'])


#________Play Sequence_________

    #design a 16th step counter
sixTeenths = []
for i in range(16):
    sixTeenths.append(i * 0.25)

    #counter with repeats
for repeats in range(4):
        #counter
    time_zero = time.time()
        #amount of steps
    for index in range(16):
        print(index)
            #on button for while loop
        running = True
            #targetTime is where the next hit should be. We use the sixTeenths[]
        targetTime = sixTeenths[index]
        while running:
                #what is the time now
            currentTime = time.time() - time_zero
                #has the clock hit the targetTime?
            if currentTime >= targetTime:
                    #turn off the while loop to go to the next step
                running = False
            else:
                time.sleep(0.001)
