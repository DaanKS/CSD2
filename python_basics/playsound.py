import simpleaudio as sa


nPlays = int(input("how many times you wanna hear this? "))
wave_obj = sa.WaveObjs

while(nPlays > 0):
    play_obj = wave_obj.play()
    play_obj.wait_done()
    nPlays -= 1
    if nPlays == 0:
        print("Done playing ")
