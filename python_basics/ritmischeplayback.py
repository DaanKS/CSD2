import simpleaudio as sa
from time import sleep

wave_obj = sa.WaveObject.from_wave_file("/home/daanaanaaan/Documents/Samples/Kick_bip.wav")
beatsPerMin = int(input("Enter # for BPM "))
quarterNote = 60 / beatsPerMin

numTrigger = int(input("Enter # for Amount of Plays "))
triggers = []

for i in range(numTrigger):
    triggers.append(quarterNote * float(input("Note Length float ")))

for i in triggers:
    play_obj = wave_obj.play()
    sleep(i)
