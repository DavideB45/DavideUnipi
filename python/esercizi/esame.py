def find_A_in_B(A, B):
	#creo un dizionario per semplificare la ricerca
	Dictionary = {}
	for i in range(B.__len__()):
		for j in range(B[i].__len__()):
			if(Dictionary.get(B[i][j])==None):
				Dictionary[B[i][j]] = 1
			else:
				Dictionary[B[i][j]] = Dictionary[B[i][j]] + 1
	
	#cerco A in B
	for i in range(A.__len__()):
		for j in A[i]:
			if(Dictionary.get(j)==None or Dictionary.get(j)==0):
				#non c'e' il numero o non occorre abbastanza volte
				return False
			else:
				#rimuovo un' occorrenza
				Dictionary[j] = Dictionary[j] - 1
	#ho trovato tutta A
	return True

#crea e riempie una matice
def fill_matrix():
	row = int(raw_input('inserisci il numero di righe : ' ))
	col = int(raw_input('inserisci il numero di colonne : '))
	#creo e inizializzo una matrice
	matr = [[0]*col for i in range(row)]
	for i in range(row):
		x = raw_input('inserisci riga : ')#legge la riga
		x = x.partition('\r')[0]
		matr[i] = x.split(' ')
	#ritorno tutte le informazioni sulla matrice in una tupla
	return (matr, row, col)


#int main(void){
(A, a_row, a_col) = fill_matrix()#creo A
(B, b_row, b_col) = fill_matrix()#creo B
if (a_col*a_row <= b_col*b_row):
	print(find_A_in_B(A, B))
else:
	print(find_A_in_B(B, A))
	#return 0
#}