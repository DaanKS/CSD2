import simpleaudio as sa
import time
import random
from midiutil import MIDIFile

#rhythm generation through simple lindenmayer system

#___________setup___________
kick = {'instrument':"kick", 'instrumentName': "kick"}
mid = {'instrument':"mid",'instrumentName': "mid"}
tom = {'instrument':"tom", 'instrumentName': "tom"}
instruments = [kick, mid, tom]
instrumentMidiNums = [36, 40, 45]
instrumentNames = ["kick", "mid", "tom"]

BPM = 120

#make use of time_signature to conform to assignment
numerator =  4
denominator = 4

#because lindenmayer systems work recursively we have to make it stop somewhere
#numGenerations is the depth of recursiveness.
numGenerations = 1
#1 = hit, 0 = rest.
#if 1 is given, send 1-0
# if 0 is given, send 1
rules = {1 : [1,0], 0 : [1] }
linden = [1]

#___________methods__________

#to avoid infinite recursion, a for loop is used to limit the amount of generations
def spawnSystem(linden, numGeneration):
    for i in range(numGeneration):
        linden += lindenCompute(linden)
#applies the predetermined rules of the system
#checks last element of the system to decide what must come next.
def lindenCompute(linden):
    return rules[linden[len(linden) - 1]]


print(linden)
spawnSystem(linden, 1)
linden.pop(0)
print (linden)
