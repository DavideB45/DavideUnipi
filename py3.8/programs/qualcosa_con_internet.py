#pandas requests beautifulsoup4
import pandas as pd
import requests
from bs4 import BeautifulSoup

#cerca la pagina
page = requests.get('https://forecast.weather.gov/MapClick.php?lat=28.56604489500006&lon=-81.68864878999995#.XinRGshKhhE')
#serve per semplificare la ricerca
soup = BeautifulSoup(page.content, 'html.parser')
#soup.find_all('a') links

#copio la cosa che mi interessa
#e' tutto in html
#per trovare l'oggetto basta ispezionare il sito
#in html e andare con il mouse sulla cosa che vogliamo

#la parte con le immagini del cielo 
week = soup.find(id='seven-day-forecast-body')
#la lista delle singole immagini(non le immagini gli oggetti)
items = week.find_all(class_ = 'tombstone-container')



#esempio di come si cerca un pezzetto
#per farne una stringa
#print(items[0].find(class_='temp temp-high').get_text())



#quando
print(items[0])
period_names = [item.find(class_='period-name').get_text() for item in items]
#come e' il tempo in parole
short_desc = [item.find(class_='short-desc').get_text() for item in items]
#temperatura
temp = [item.find(class_='temp').get_text() for item in items]
print(temp)

#temp format = '(High|low): %d °F'
for i in range(temp.__len__()):
	temperatuta_x = temp[i].split(' ')#divido la temperatura dal resto
	temperatuta_x[1] = str(int((int(temperatuta_x[1])-32)/1.8))#tresformo in °C
	temp[i] = ' '.join([temperatuta_x[1], '°C'])#gli do il formato piu' bello

weather_stuff = pd.DataFrame({
	'qunado': period_names,
	'tempo': short_desc,
	'temperature': temp
})


print(weather_stuff)

#weather_stuff.to_csv('weather.csv')