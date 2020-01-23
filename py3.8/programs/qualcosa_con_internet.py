#pandas requests beautifulsoup4
import requests
from bs4 import BeautifulSoup

page = requests.get('https://forecast.weather.gov/MapClick.php?lat=28.56604489500006&lon=-81.68864878999995#.XinRGshKhhE')
#serve per semplificare la ricerca
soup = BeautifulSoup(page.content, 'html.parser')
#soup.find_all('a') links

#copio la cosa che mi interessa
week = soup.find(id='seven-day-forecast-body')
items = week.find_all(class_ = 'tombstone-container')
print(items[1])