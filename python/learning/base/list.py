def stacca():
	for i in range(5):
		i = i#da fastidio giallo
		print("#######################")


x_files = [1, 2, "cose", 'non ha senso', False, 21]
print(x_files)
print(x_files[3])
print(x_files[-1])
print(x_files[0:2])
##################################
stacca()##########################
##################################
length = x_files.__len__()
x_files.insert(1, "yo boy")
for i in range(length):
	print(x_files[i])
##################################
stacca()##########################
##################################
#sort 
print('\n')
x_files = 'davide borghini'
x_files = list(x_files)
x_files.reverse()#ribalta la lista
x_files = str(x_files)
print(x_files)
#non funziona
##################################
stacca()##########################
##################################
l1 = "pollo"
#devo fare i cast anche se di base e' una union...
l1 = list(l1)
#senza l2 era un mero puntatore qundi girava ance l1
l2 = list(l1)
#
l2.reverse()
#sono diverse (in ocaml e' piu' bello)
if l1 == l2:
	print("palindroma")
else:
	print("NO")
print(l1)
print(l2)
##################################
stacca()##########################
##################################

#
last_list = []
#per scegliere la dimensione
last_list.extend(range(21))
#stupido pyton
for i in range(21):
	last_list[i] = i
print(last_list[0:21:2])
print(last_list[::-1])

max = len(last_list)
for i in range(max):
	print(last_list[max:max-1-i:-1])