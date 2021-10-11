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

#TODO make this different
theGroove=[0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5]
while len(theGroove) > 0:
    timeStamps.append(theGroove[0] * (quarterNote/4))
    theGroove.pop(0)
#remove extraneous timestamp
timeStamps.pop()

for i in range(len(timeStamps)):
    events.append(make_event(timeStamps[count], instruments[random.randint(0, 1)]))
    count += 1
#fill in 16th notes
for sixteenthNote in range(16):
    events.append(make_event(sixteenthNote, instruments[2]))

#Took this line from Wouter Ensink
events.sort(key=lambda x: x['timeStamp'])


time_zero = time.time()
