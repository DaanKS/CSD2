# import simpleaudio as sa
import time

#using strings to emulate use of simpleaudio

#load sample in variable
#wave_obj = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Kick_bip.wav")
wave_obj = "Kick"
def play(wave_obj):
    print(wave_obj)

#calculate time length of a quarternote
beatsPerMin = int(input("Enter # for BPM "))
quarterNote = 60 / beatsPerMin

#prepare list of 16th notes
theGroove = [0, 1, 3, 7, 11, 12, 15]

#timeDurations = []
timeStamps=[0]
#timeLength = 0
#transform 16th notes into timestamps
#step1 from 16th notes to time durations
#step2 from time durations to timestamps
while len(theGroove) > 0:
    timeStamps.append(theGroove[0] * (quarterNote/4))
    theGroove.pop(0)

print(timeDurations)



#playtimestamps
