import datetime
from datetime import datetime
#per l'input
y = 'y'
n = 'n'

#restituisce ora min sec
#sottoforma di tupla di stringhe 
def best_time(delta):
	delta = delta.split(':')
	H = delta[0]
	M = delta[1]
	S = delta[2]
	delta = ' '.join([H, 'h', M, 'min', S, 'sec'])
	return delta

#diminuisce di 1h il delta_t
#calcolato da tempo finale - now()
def calcola_diff(T_F, T_I):

	delta = str(T_F - T_I)
	
	if delta.find('day') != -1:
		#l'evento e' tra piu' di 24 h
		return best_d(delta)
	else:
		return best_time(delta)

#rende piu bella una stringa 
#prende un elemento str
#generato da un tipo datetime
def best_d(string):
	string = string.split(' ')
	string[1] = 'giorni'
	tempo = string[2].split(':')
	tempo.append('sec')
	tempo.insert(2, 'min')
	tempo.insert(1, 'h')
	string[2] = ' '.join(tempo)
	return ' '.join(string)


def main():

	orario = True
	scelta = input('inserire evento [y][n] ')
	if scelta == 'y':
		anno = int(input('inserire l\'anno : '))
		mese = int(input('inserire il mese : '))
		giorno = int(input('inserire il giorno : '))
		scelta = input('inserire orario [y][n] ')
		if scelta == 'y':
			ora = int(input('inserire ora : '))
			minuti = int(input('inserire i minuti : '))
			evento = datetime(anno, mese, giorno, ora, minuti)
		else:
			orario = False
			evento = datetime.date(datetime(anno, mese, giorno))
	else:
		inizio_uni = datetime(2020, 2, 17, 9)
		evento = inizio_uni

	if orario == True:
		ora = datetime.now()
		delta = calcola_diff(evento, ora)
		print(delta)
	else :
		adesso = datetime.date(datetime.now())
		delta = str(evento - adesso)
		delta = delta.split(' ')
		if delta[0] == '1':
			print('domani bro!')
		else:
			print(' '.join([delta[0],"days"]))



if __name__ == "__main__":
	main()