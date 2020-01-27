#liste con elementi che non possono contenere duplicati
#non hanno un ordine (e' propio fatto a caso)
#sono utili per gestire gli insiemi
#{}brakets

#base
s = {'banana', 'blueberry', 'raspberry'}
s.add("ananas")
s.add("blueberry")#non fa nulla

#rimuovere duplicati da una lista
l = [2, 3, 1, 2, 3, 1, 1, 2, 4, 5, 4, 5, 5, 2]
no_duplicate = set(l)
l = list(no_duplicate)
print(l)

#insiemi
library_1 = {'Harry potter', 'Hunger Games', '22.11.63', 'Dracula'}
library_2 = {'Harry potter', 'Hunger Games', 'The scarlet letter', 'Romeo & Juliet'}
#summ together with no duplicate
books = library_1.union(library_2)
print(books)
#thing in common
books = library_1.intersection(library_2)
print(books)
#difference = what is in one that isn't in two
books = library_1.difference(library_2)
print(books)
#clear (svuota tutto)