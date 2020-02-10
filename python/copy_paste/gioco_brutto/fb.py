import pygame
import random
import os


pygame.init()

#load img
dirname = os.path.dirname(os.path.abspath(__file__))

bird = pygame.image.load(os.path.join(dirname, 'bestia'))
bird = pygame.transform.scale(bird, (57,50))

bg = pygame.image.load(os.path.join(dirname, 'bg.png'))
bg = pygame.transform.scale(bg, (400,600))


#gb
WN = pygame.display.set_mode((400,600))
FPS = 50

def init():
	global x_pos, y_pos, v_y
	x_pos, y_pos = 0, 0
	v_y = 0
init()

def draw():
	WN.blit(bg, (0,0))
	WN.blit(bird, (x_pos, y_pos))

def update_wn():
	pygame.display.update()
	#pygame.Clock,time(FPS)

go_on = True
while go_on:
	v_y += 1
	y_pos += v_y
	draw()
	update_wn()
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE:
			pygame.quit()
			go_on = False