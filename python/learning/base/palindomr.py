world = raw_input("inserisci una parola : ")
while world != 'FINE\r':
	
	l1 = list(world)
	l1.remove('\r')
	l2 = list(l1)
	l2.reverse()

	if l2 == l1:
		print("Palindroma")
	else:
		print("Non palindroma")
	world = raw_input("inserisci una parola : ")