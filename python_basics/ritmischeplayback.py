import simpleaudio as sa
from time import sleep

#load sample in variable
wave_obj = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Kick_bip.wav")

#calculate time length of a quarternote
beatsPerMin = int(input("Enter # for BPM "))
quarterNote = 60 / beatsPerMin

#amount of triggers + initialize array for calculated amount of time per trigger
numTrigger = int(input("Enter # for Amount of Plays "))
triggers = []
for i in range(numTrigger):
    #insert sleep durations per trigger in the  array
    triggers.append(quarterNote * float(input("Note Length float ")))

#play
for i in triggers:
    play_obj = wave_obj.play()
    sleep(i)

#Perhaps adding Multithreading is a fun idea for polyrhythms and polyphone playback
