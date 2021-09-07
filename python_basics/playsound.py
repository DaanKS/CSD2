import simpleaudio as sa

wave_obj = sa.WaveObject.from_wave_file("/Users/dean/Documents/CSD2/python_basics/HHOP_9.mp3")
print("playing")
play_obj = wave_obj.play()
play_obj.wait_done()
