import simpleaudio as sa
import time as ti
import random
from midiutil import MIDIFile

#___________setup___________
kick = sa.WaveObject.from_wave_file("/Users/dean/Documents/samples/kick.wav")
mid = sa.WaveObject.from_wave_file("//Users/dean/Documents/samples/block.wav")
high = sa.WaveObject.from_wave_file("/Users/dean/Documents/samples/hat.wav")
instruments = [kick, mid, high]
events = []
allSteps = []
kickPercentage = []
midPercentage = []

#__________methods___________

def makeEvent(timestamp, instrument, midiNote):
    return{}



#We are using lindenmayer systems to fill in the probabilities
