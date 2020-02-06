#creare un programma che legga frasi fino a che viene inserita la parola fine
#ristampare le frasi lette riga per riga
#in modo che siano centrate tipo :
#    frase
# con le righe
#   scritte   
#    belle

i = 0
leng = 4
phrases = []
phrases.append(raw_input("inserire la riga\n"))
if phrases[i].__len__() > leng:
	leng = phrases[i].__len__()

while phrases[i] != "fine":
	i = i + 1
	phrases.append(raw_input("inserire la riga\n"))
	if phrases[i].__len__() > leng:
		leng = phrases[i].__len__()

print(leng)
phrases.remove("fine")

for line in phrases:
	space = ' '*((leng - line.__len__())/2)
	print('  '.join([space, line]))

#pensavo fosse piu' difficile