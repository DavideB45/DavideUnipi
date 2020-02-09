import pygame
import random
import os


pygame.init()

#load img
dirname = os.path.dirname(os.path.abspath(__file__))
bird = pygame.image.load(os.path.join(dirname, 'bestia'))
#bird = pygame.image.load('gov')


#gb
WN = pygame.display.set_mode((400,600))
FPS = 50

def init():
	global x_pos, y_pos, v_y
	x_pos, y_pos = 0, 0
	v_y = 0
init()

def draw():
	WN.blit(bird, (x_pos, y_pos))

def update_wn():
	pygame.display.update()
	#pygame.time.Clock.tick(FPS)

while True:
	#v_y += 1
	#y_pos += v_y
	draw()
	update_wn()