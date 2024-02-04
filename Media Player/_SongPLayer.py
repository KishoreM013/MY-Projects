from pygame import mixer
import os
from sys import exit


def next_song(n):
    return n+1


def previous_song(n):
    return n-1


mixer.init()
# to store song
song = []

song.append("ADarkXsweater.mp3")
song.append("CountStr.mp3")
song.append("Maryoncros.mp3")
song.append("BLights.mp3")
song.append("Arcade.mp3")
song.append("Shapeofu.mp3")
song.append("WSV.mp3")
song.append("Levitating.mp3")
song.append("GigaChad-theme.mp3")
song.append("Runaway.mp3")
song.append("All-We-Know.mp3")
song.append("Memory-Robot.mp3")
song.append("Industry-baby.mp3")

position = 0
while True:
    os.system('cls')
    print("\n\t\tPlaying : ", song[position], "\n\n\tNumber of Songs : ", len(song))
    print("\tCurrent Song Number : ", position+1)
    mixer.music.load(song[position])
    mixer.music.play()
    do = input("\n\n\tExit-x \n\tPause-p \n\tResume-r \n\tNext-n \n\tBefore-b \n\n\t--Enter Your Choice : ")
    if do == 'x':
        os.system('cls')
        mixer.music.pause()
        print("\n\n\tDo you feel better now ?...")
        exit("\n\tWelcome back...")
    elif do == 'p':
        print("\n\tSong is Paused....")
        mixer.music.pause()
        to = input("\n\tEnter r to resume : ")
        if to == 'r':
            mixer.music.unpause()
            position = position-1
    elif do == 'n':
        if position == len(song)-1:
            position = 0
        else:
            position = next_song(position)
        continue
    elif do == 'b':
        if position == 0:
            pos = len(song)-1
        else:
            position = previous_song(position)
        continue
    if position == len(song)-1:
        position = 0
    else:
        position += 1
