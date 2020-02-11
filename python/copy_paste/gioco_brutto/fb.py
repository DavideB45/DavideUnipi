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
pipe = pygame.image.load(os.path.join(dirname, 'pipe.png'))
pipe_down = pygame.transform.scale(pipe, (60, 220))
pipe_up = pygame.transform.flip(pipe_down, False, True)

#gb
WN = pygame.display.set_mode((400,600))
FPS = 50


class tubi:
	def __init__(self):
		self.x = 400
		self.y = random.randint(300, 420)
	def move(self):
		self.x -= 0.1
		WN.blit(pipe_down, (self.x, self.y))
		WN.blit(pipe_up, (self.x, self.y - 380))
	def ceck_hit(self, y_pos):
		b_dx = 5 + bird.get_width()
		b_sx = 5
		print(self.y - 160, y_pos)
		'''y_pos + bird.get_height() < self.y and'''
		if y_pos + bird.get_height() > self.y or y_pos < self.y -160:
			if b_sx < self.x + pipe.get_width() and b_dx > self.x:
				sconfitta()

def init():
	global x_pos, y_pos, v_y
	x_pos, y_pos = 0, 0
	v_y = 0
	global ostacoli
	ostacoli = []
	ostacoli.append(tubi())
	ostacoli.append(tubi())
	ostacoli.append(tubi())
	ostacoli[1].x = 600
	ostacoli[2].x = 800
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

def sconfitta():
	WN.blit(death, (100, 0))
	pygame.display.update()
	wait4q()

def draw():
	WN.blit(bg, (0,0))
	for tubo in ostacoli:
		tubo.move()
	if ostacoli[0].x < -60:
		to_kill = ostacoli[0]
		ostacoli.remove(to_kill)
		ostacoli.append(tubi())
		ostacoli[-1].x = ostacoli[-2].x + random.randint(180, 250)
	WN.blit(bird, (5, int(y_pos)))
	WN.blit(ground, (int(x_pos),500))
	pygame.display.update()
	ostacoli[0].ceck_hit(y_pos)
	if y_pos > 488:
		sconfitta()

def update_wn():
	pygame.display.update()
	#pygame.Clock,time(FPS)

v_y = 0.5
go_on = True
while go_on:
	y_pos += v_y
	x_pos -= 0.1
	if x_pos < -100:
		x_pos = 0
	v_y = 0.1
	update_wn()
	draw()
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_SPACE:
				pygame.quit()
				go_on = False
			if event.key == pygame.K_1:
				v_y = -50