import pygame
import random
import os


pygame.init()
clock = pygame.time.Clock()
clock.tick(60)


#load img
dirname = os.path.dirname(os.path.abspath(__file__))
bird = pygame.image.load(os.path.join(dirname, 'bestia'))
bird = pygame.transform.scale(bird, (57,50))
bg = pygame.image.load(os.path.join(dirname, 'bg.png'))
bg = pygame.transform.scale(bg, (400,600))
ground = pygame.image.load(os.path.join(dirname, 'ground.png'))
ground = pygame.transform.scale(ground, (500, 112))
death = pygame.image.load(os.path.join(dirname, 'gov.jpg'))
death = pygame.transform.scale(death , (200, 200))

#gb
WN = pygame.display.set_mode((400,600))
FPS = 50

def init():
	global x_pos, y_pos, v_y
	x_pos, y_pos = 0, 0
	v_y = 0
init()

def wait4q():
	waiting = True
	while waiting:
		for event in pygame.event.get():
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_SPACE:
					pygame.quit()
					exit()
				if event.key == pygame.K_q:
					waiting = False
					init()		

def draw():
	WN.blit(bg, (0,0))
	WN.blit(bird, (5, int(y_pos)))
	x_pos = 1
	if x_pos > 50:
		x_pos = 0
	WN.blit(ground, (x_pos,500))
	if y_pos > 488:
		WN.blit(death, (100, 0))
		wait4q()

def update_wn():
	pygame.display.update()
	#pygame.Clock,time(FPS)

v_y = 0.5
go_on = True
while go_on:
	y_pos += v_y
	v_y = 0.1
	draw()
	update_wn()
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_SPACE:
				pygame.quit()
				go_on = False
			if event.key == pygame.K_1:
				v_y = -50