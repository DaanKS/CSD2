import simpleaudio as sa
import time
import random

#loading up samples
#using strings for now to emulate use of simpleaudio
kick = "kick"#sa.WaveObject.from_wave_file("../Samples/Kick_bip.wav")
mid = "mid"#sa.WaveObject.from_wave_file("../Samples/Mid_bip.wav")
tom = "tom"#sa.WaveObject.from_wave_file("../Samples/Tom_bip.wav")

def play(instrument):
    print(instrument)

bpm = 120
quarterNote = 60 / bpm
instruments = [kick, mid, tom]
timeStamps = []

def make_event(timestamp, instrument):
    return {'timeStamp': timestamp, 'instrument' : instrument}
events = []

theGroove=[0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25]
while len(theGroove) > 0:
    timeStamps.append(theGroove[0] * (quarterNote/4))
    theGroove.pop(0)

timeStamps.pop()
count = 0
for i in range(len(timeStamps)):
    events.append(make_event(timeStamps[count], instruments[random.randint(0, 2)]))
    count += 1

print (events)
