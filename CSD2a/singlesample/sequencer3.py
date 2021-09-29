import simpleaudio as sa
import time

#using strings to emulate use of simpleaudio

#load sample in variable
wave_obj = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Kick_bip.wav")

def play(wave_obj):
    play_obj=wave_obj.play()

#calculate time length of a quarternote
beatsPerMin = int(input("Enter # for BPM "))
quarterNote = 60 / beatsPerMin

numTrigger = int(input("Enter # for Amount of Plays "))
triggers = []
for trigger in range(numTrigger):
    #insert sleep durations per trigger in the  array
    triggers.append(float(input("Note Length float ")))

#theGroove is a list that holds 16th notes
theGroove = [0]
#add function to transform quarternote time values to 16th notes
for trigger in triggers:
    theGroove.append(theGroove[-1] + (4 * trigger))
#remove the last one, because it displays the end of the final hit
theGroove.pop()
print (theGroove)

timeStamps=[]
#transform 16th notes into timestamps
while len(theGroove) > 0:
    timeStamps.append(theGroove[0] * (quarterNote/4))
    theGroove.pop(0)
#measuring point for time
print(timeStamps)
time_zero = time.time()
#a loop that calcuates the elapsed time and based on that decides whether...
#...a note is played or not.
#check time
while len(timeStamps) > 0:
    currentTime = time.time() - time_zero
    if(currentTime >= timeStamps[0]):
        timeStamps.pop(0)
        play(wave_obj)
    time.sleep(0.001)
