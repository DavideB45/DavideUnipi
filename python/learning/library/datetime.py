import datetime
from datetime import datetime
from datetime import timedelta
#forse basta scrivere 
#from datetime import *

today = datetime.now()
birthday = datetime(2020, 9, 24)
print(today)
#print(today.day)
#print(today.month)
#print(today.year)
print(today.weekday())
print(repr(today))
print(birthday)
print(datetime.time(today))

#em ok capisci oh me del futuro che non ne ho voglia
#comunque, per ottenere il giorno devi
#prima creare l'oggetto che indica adesso 
#poi trasformalo in data (senza ore e robe cosi')
#utilizzando il comando sotto
#forse si puo' fare meglio ma non ci riesco qindi
#accontentati
today = datetime.date(today)
print(today)

#timedelta
today = datetime.now()
print('\nDelta')
delta = timedelta(hours=2)
print(today + delta)

#time to birthday
#while True:
#	day_to_birthday = (birthday - datetime.now())
#	print(day_to_birthday)

print('\n\n\n')
inizio_uni = datetime.date(datetime(2020, 2, 17))
#dice che giorno e'
adesso = datetime.date(datetime.now())
print('alla scuola mancano')
print(inizio_uni - adesso)



#datetime
#non ce la posso fare


#string formatting nel verso normale
#strftime (f = formatting)
oggi_giorino = datetime.now()
print(oggi_giorino.strftime('today is the %d of %B %Y'))
#%B month
#%d day
#%Y year

#March 9, 2019 -> datetime object (2019-03-09)
#strptime (p = parsing)
date = datetime.strptime('march nanana 09, 2019', '%B nanana %d, %Y')
print("\n\n")
print(date)
print(repr(date))
#maya per gestire meglio gli orari
#dicono che sia piu' umano
#https://github.com/kennethreitz/maya