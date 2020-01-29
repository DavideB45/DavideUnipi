#basic version of tempo_.py
import datetime
from datetime import datetime

it_dicltionary = {
	'ins':   'inserisci',
	'd':     'giorno',
	'ds':    'giorni',
	'm':     'mese',
	'y':     'anno',
	'miss':  'mancano',
	'tomor': 'domani',
	'today': 'oggi'
}

en_dictionary = {
	'ins':   'insert',
	'd':     'day',
	'ds':    'days',
	'm':     'month',
	'y':     'year',
	'miss':  'missing',
	'tomor': 'tomorrow',
	'today': 'today'
}

def calc_delta(event):
	now = datetime.date(datetime.now())
	event = datetime.date(event)
	delta = str(event - now)
	delta = delta.split(' ')[0]
	return delta

#crea una frase da un dizionario e
#una lista di elementi/parole
def create_phrase(dictionary, lista):
	#aggiunge parole del dizionario
	to_join = [dictionary.get(item) for item in lista]
	#aggiunge parole non trovate
	for i in range(to_join.__len__()):
		item = to_join[i]
		if item == None:
			to_join[i] = lista[i]
	to_join.append(' ')
	#rende maiuscola la prima lettera
	to_join[0] = to_join[0].capitalize()
	#ritorna la frase come stringa
	return ' '.join(to_join)




#int main(void):
#scelta della lingua
choise = raw_input('pick a language [en][it] ')
if choise == 'en\r':
	curr_dictionary = en_dictionary
else:
	curr_dictionary = it_dicltionary

#immissione del giorno
y = int(input(create_phrase(curr_dictionary,['ins', 'y', ":"])))
m = int(input(create_phrase(curr_dictionary,['ins', 'm', ":"])))
d = int(input(create_phrase(curr_dictionary,['d'," = "])))

#calcolo della distanza (in giorni)
event = datetime(y, m, d)
delta = calc_delta(event)

#stampa singolare o plurale
if delta == '1':#tomorrow
	print(create_phrase(curr_dictionary,['miss', '1', "d"]))
elif delta == '0:00:00':#today
	print(create_phrase(curr_dictionary,['today','brath','!']))
else:#toyota
	print(create_phrase(curr_dictionary,['miss', delta, 'ds']))