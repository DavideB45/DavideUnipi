from obj import *
import pygame
import os

pygame.init()
clock = pygame.time.Clock()
clock.tick(60)
WN = pygame.display.set_mode((600,400))

dirname = os.path.dirname(os.path.abspath(__file__))
bestia = pygame.image.load(os.path.join(dirname, 't-rex.png'))
bestia = pygame.transform.scale(bestia, (128, 128))
cactus = pygame.image.load(os.path.join(dirname, 'cactus.png'))
cactus = pygame.transform.scale(cactus, (128, 128))
bg = pygame.image.load(os.path.join(dirname, 'ground.png'))
bg = pygame.transform.scale(bg, (600, 500))

def ceck_event():
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			pygame.quit()
			global go_on
			go_on = False
		if event.type == pygame.KEYDOWN:
			if y_pos > 270:
				global y_speed
				y_speed = -0.6

x_pos = 600
y_pos = 279
y_speed = 0
def display():
	WN.blit(bg, (0,-100))
	WN.blit(bestia, (20, y_pos))
	WN.blit(cactus, (int(x_pos), 290))
	pygame.display.update()

go_on = True
while go_on:
	x_pos -= 0.1
	if x_pos < -70:
		x_pos = 600
	y_pos += y_speed
	if y_pos >= 279:
		y_speed = 0
		y_pos = 279
	else:
		y_speed += 0.0007
	display()
	ceck_event()