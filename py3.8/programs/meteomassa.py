import requests
from bs4 import BeautifulSoup


page = requests.get('http://www.meteoapuane.it/previsioni.php')
soup = BeautifulSoup(page.content, 'html.parser')

# Crea temperature minime #########################################
temperature = soup.find_all(class_='testoBLU')                    #
temp_min = [temperature[1 + i*5].get_text() for i in range(3)]    #
# Crea temperature massime ########################################
temperature = soup.find_all(class_='testoROSSO')                  #
temp_max = [temperature[1 + i*5].get_text() for i in range(3)]    #
# Crea il cielo con valori della legenda ##########################
days = soup.find_all(id='massa')                                  #
future = days.__len__()                                           #
pre_N = '<div id="massa"><img alt="*" src="img/previsioni/'       #
cielo = []                                                        #
for i in range(future):                                           #
	cielo.append(                                                 #
		str(days[i]).partition(pre_N)[2].partition('.')[0])       #
###################################################################

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
giorno = ['      OGGI  \n', '    DOMANI  \n', 'DOPODOMANI  \n']

print('\n<----------------------------------------->\n')
for i in range(future):
	day_index = int(i/2)
	if i % 2 == 0:
		print('             ',giorno[day_index])
		print('temp max = ',temp_max[day_index],'\ntemp min = ',temp_min[day_index],'\n')
		print(' mattina:  ',legenda[cielo[i]])
	else:
		print('pom/sera:  ',legenda[cielo[i]])
		print('\n<----------------------------------------->\n')