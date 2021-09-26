# import simpleaudio as sa
import time

#using comments to emulate use of simpleaudio

#load sample in variable
#wave_obj = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Kick_bip.wav")
wave_obj = "Kick"
def play(wave_obj):
    print(wave_obj)

#calculate time length of a quarternote
beatsPerMin = int(input("Enter # for BPM "))
quarterNote = 60 / beatsPerMin

#amount of triggers + initialize array for calculated amount of time per trigger
numTrigger = int(input("Enter # for Amount of Plays "))
triggers = []
for trigger in range(numTrigger):
    #insert sleep durations per trigger in the  array
    triggers.append(quarterNote * float(input("Note Length float ")))

#create list of timestamps
#so the trick here is to transform quarternote values to points on a timeline
#by adding the durations, starting at 0 (if there is no rest in the start)
#0: 0
#1: 0 + length of the note
#2: 0 + legnth of the note + length of note 2 and so on
timeStamps=[0]
timeLength = 0
for notes in triggers:
    timeLength += notes
    timeStamps.append(timeLength)
#print(timeStamps)
#TODO this leaves us with a list of one too many. For now we can remove it
timeStamps.pop()
print(timeStamps)

#measuring point for time
time_zero = time.time()



for i in triggers:
    play(wave_obj)
    time.sleep(i)
