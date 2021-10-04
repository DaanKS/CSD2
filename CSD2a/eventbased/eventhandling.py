import simpleaudio as sa
import time

#testing event things and dictionaries.

#loading up samples
kick = "kick"#sa.WaveObject.from_wave_file("../Samples/Kick_bip.wav")
mid = "mid"#sa.WaveObject.from_wave_file("../Samples/Mid_bip.wav")
tom = "tom"#sa.WaveObject.from_wave_file("../Samples/Tom_bip.wav")

kick_event = {
'timestamp': 1000,
'instrumentname' : "kick",
'instrument' : kick,
'velocity' : 120,
'duration' : 250
}

mid_event = {
'timestamp' : 2000,
'instrumentname' : "mid",
'instrument' : mid,
'velocity' : 90,
'velocity' : 250
}

tom_event = {
'timestamp' : 3000,
'instrumentname' : "tom",
'instrument' : tom,
'velocity' : 70,
'duration' : 500
}

def handle_note_event(event):
    print(event['instrumentname'])
#    event['instrument'].play()

#extract timestamp from each event and
events_oh = [kick_event, mid_event, tom_event]
timeStamps = []

for event_oh in events_oh:
    timeStamps.append(event_oh['timestamp'])

print(timeStamps)
#have a timestamp loop to play events in time
time_zero = time.time()
note = 0

while len(timeStamps) > 0:
    currentTime = time.time() - time_zero
    #right now timeStamps[] is in ms so we use /1000 to convert to seconds
    if(currentTime >= timeStamps[0] / 1000):
        handle_note_event(events_oh[note])
        note+= 1
        timeStamps.pop(0)
    time.sleep(0.001)
