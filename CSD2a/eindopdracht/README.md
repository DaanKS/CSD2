Python Drum Sequencer

Welcome to my Drum Sequencer!

A Drum Sequencer capable of executing odd measures (including measures like 13/53)
and printing generated rhythms to midi files.


Techniques used:
Lindenmayer Systems
Probability Based Rhythm Generation

Why did I opt for these techniques?

A common concept in current music is that Repetition Legitimises. What is nice about
a Lindenmayer system is that it generates lists that consist of repeated patterns.
This gives the audience the ability to latch onto seemingly random rhythms - And still
be able to decipher the pulse.  
Instead of filling the Lindenmayer system with one's and zero's (one meaning a hit
and zero meaning no hit or vice versa) I decided to fill the outcomes with numbers that
resemble percentages (probabilities). This was to be able to generate fresh rhythms
without having to produce new lindenmayer systems.

The Process:
Assuming you are in the correct directory
Open Terminal and type: python3 eindopdrachtFinal.py

You will then be asked to fill in the Beats Per Minute.
After you will be asked to put an integer for the numerator and denominator of the time signature
The programme asks you for an integer - this can be any integer. This number is used with
modulo to select a starting input for each of the lindenmayer systems.

Leave the computer to generate a rhythm. As soon as it's ready it will play the rhythm
so make sure the sound is on.
If you like what you heard and you want it in midi, when prompted press 'y'
and the programme will write all the information to midi and subsequently close itself.
If you want the programme to generate a new rhythm press 'n' instead of 'y' when prompted
and the programme will generate a new rhythm based on the previously determined probabilities.


Thank you.

DS
