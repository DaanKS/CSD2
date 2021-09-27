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
while len(theGroove) > 0:
    timeStamps.append(theGroove[0] * (quarterNote/4))
    theGroove.pop(0)


#measuring point for time
time_zero = time.time()
#a loop that calcuates the elapsed time and based on that decides whether
#a note is played or not.

#check time
while len(timeStamps) > 0:
    currentTime = time.time() - time_zero
    if(currentTime >= timeStamps[0]):
        timeStamps.pop(0)
        play(wave_obj)
    time.sleep(0.001)
