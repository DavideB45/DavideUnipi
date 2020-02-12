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
WN = pygame.display.set_mode((400,600))#finestra
FPS = 50#non usata
Font = pygame.font.SysFont('Comic Sans MS', 40)#font
v_x = 0.36#velocita' x

#uno vale come quello sopra e quello sotto
class tubi:
	#calclolo altezza
	def __init__(self):
		self.x = 400
		self.y = random.randint(300, 420)
	#animazone del movimento e basta
	def move(self):
		self.x -= v_x
		WN.blit(pipe_down, (self.x, self.y))
		WN.blit(pipe_up, (self.x, self.y - 380))
	#calcolo se itta
	def ceck_hit(self, y_pos):
		b_dx = 5 + bird.get_width() #bestia a dx
		b_sx = 5#bestia a sx
		print(self.y - 160, int(y_pos), self.y)
		#controllo altezza
		if y_pos + bird.get_height() > self.y or y_pos < self.y -160:
			#controllo larghezza
			if b_sx < self.x + pipe.get_width() and b_dx > self.x:
				sconfitta()

#inizializza tutte le variabuli quando si riinizia una partita
def init():
	global x_pos, y_pos, v_y
	x_pos, y_pos = 0, 0
	v_y = 0
	global point
	point = 0
	global ostacoli
	ostacoli = []#lista di oggetti (tubi)
	ostacoli.append(tubi())
	ostacoli.append(tubi())
	ostacoli.append(tubi())
	ostacoli[1].x = 600
	ostacoli[2].x = 800
init()

#aspetta che venga schiacciato il pulsante q per rigiocare
#oppure il tasto spazio per uscire dal gioco
def wait4q():
	waiting = True
	while waiting:
		for event in pygame.event.get():
			if event.type == pygame.KEYDOWN:
				#spazio
				if event.key == pygame.K_SPACE:
					pygame.quit()
					print(point)
					exit()
				#tasto q
				if event.key == pygame.K_q:
					waiting = False
					init()		

#mostra la scritta game over
#forse lo dovrei rifare
def sconfitta():
	WN.blit(death, (100, 40))
	pygame.display.update()
	wait4q()

#disegna tutto
def draw():
	WN.blit(bg, (0,-100))
	for tubo in ostacoli:
		tubo.move()
	#rimuove il primo ostacolo
	#ne aggiunge uno infondo
	#aggiorna il punteggio
	if ostacoli[0].x < -60:
		to_kill = ostacoli[0]
		ostacoli.remove(to_kill)
		ostacoli.append(tubi())
		ostacoli[-1].x = ostacoli[-2].x + random.randint(210, 250)
		global point
		point += 1
	punti_r = Font.render(str(point), 1, (120, 120, 120))
	WN.blit(punti_r, (180, 0))
	WN.blit(bird, (5, int(y_pos)))
	WN.blit(ground, (int(x_pos),500))
	pygame.display.update()
	#controllo le collisioni
	#con gli ostacoli
	ostacoli[0].ceck_hit(y_pos)
	#con il terreno
	if y_pos > 488:
		sconfitta()

#funzione inutile
def update_wn():
	pygame.display.update()
	#pygame.time.Clock.time(FPS)

#per redere tutto piu' bello
#record = 1500
def ceet():
	if y_pos + 60 > ostacoli[0].y:
		global v_y
		v_y = -0.59


go_on = True
while go_on:
	y_pos += v_y#caduta
	x_pos -= v_x#avanzamento
	if x_pos < -100:
		x_pos = 0
	v_y += 0.0054#accelerazione della caduta
	update_wn()
	draw()
	#ceet
	ceet()
	#controllo per uscire dal gioco e saltare
	for event in pygame.event.get():
		if event.type == pygame.KEYDOWN:
			#uscire
			if event.key == pygame.K_SPACE:
				pygame.quit()
				go_on = False
			#saltare
			if event.key == pygame.K_1:
				v_y = -0.59
#stampa i punti dell'ultima partita
print(point)