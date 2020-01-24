#pandas requests beautifulsoup4
import pandas as pd
import requests
from bs4 import BeautifulSoup


page = requests.get('https://forecast.weather.gov/MapClick.php?lat=28.56604489500006&lon=-81.68864878999995#.XinRGshKhhE')
#serve per semplificare la ricerca
soup = BeautifulSoup(page.content, 'html.parser')
#soup.find_all('a') links

#copio la cosa che mi interessa
week = soup.find(id='seven-day-forecast-body')
items = week.find_all(class_ = 'tombstone-container')
#print(items[1])

print(items[0].find(class_='period-name').get_text())
print(items[0].find(class_='short-desc').get_text())
print(items[0].find(class_='temp temp-high').get_text())

period_names = [item.find(class_='period-name').get_text() for item in items]
short_desc = [item.find(class_='short-desc').get_text() for item in items]
temp = [item.find(class_='temp').get_text() for item in items]

weather_stuff = pd.DataFrame({
	'qunado': period_names,
	'tempo': short_desc,
	'temperature': temp
})

print(weather_stuff)

weather_stuff.to_csv('weather.csv')