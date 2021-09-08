import simpleaudio as sa
from time import sleep

beatsPerMin = int(input("Enter # for BPM "))
quarterNote = 60 / beatsPerMin

numTrigger = int(input("Enter # for Amount of Plays "))

for i in range(numTrigger):
    
