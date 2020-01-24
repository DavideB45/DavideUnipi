import requests
from bs4 import BeautifulSoup


page = requests.get('http://www.meteoapuane.it/previsioni.php')
soup = BeautifulSoup(page.content, 'html.parser')

legenda = {
	'1':  'cielo coperto 1',
	'2':  'cielo coperto 2',
	'3':  'nuvoloso con foschia',
	'4':  'foschia',
	'5':  'pioggia che congela al suolo',
	'6':  'grandine / pentagoni',
	'7':  'variabile con neve',
	'8':  'variabile con rovesci deboli',
	'9':  'cielo molto nuvoloso',
	'10': 'nebbia',
	'11': 'nevischio',
	'12': 'neve forte',
	'13': 'neve mista a pioggia',
	'14': 'neve debole',
	'15': 'neve moderata',
	'16': 'cielo nuvoloso',
	'17': 'pioggia moderata',
	'18': 'pioggia forte',
	'19': 'pioggia debole',
	'20': 'cielo poco nuvoloso'
}
giorno = ['oggi', 'domani', 'dopodomani']

days = soup.find_all(id='massa')
proxi_future = days.__len__()
for i in range(proxi_future):
	if i % 2 == 0:
		print(giorno[int(i/2)],' mattina:')
	else:
		print(giorno[int(i/2)],' pomeriggio/sera:')
	day_1 = (str(days[i])).partition('<div id="massa"><img alt="*" src="img/previsioni/')
	day_1 = day_1[2].partition('.')[0]
	print(legenda[day_1])
	if i % 2 == 1:
		print('\n------------------\n')
	else:
		print()
i = input('premere invio alla fine!')
while True:
	i = i