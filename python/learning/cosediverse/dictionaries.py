#utili per organizzare dati
#tempo di accesso costante
#things have no specific order
#	-create#	-index#		-add#	-key value pairs#
#get()#items()#keys()#values()#pop()#popitem()#clear()

dictionary = {
	#key      #values
	'bananas':   5,
	'oranges':   3,
	'potatos':   8,
	'kiwi'   :   10,
	'apples' :   7
}
#values can be wathever I want

#if key is not in dictionary it gaves error
print(dictionary['bananas'])
#does not gave error if not found
print(dictionary.get('watermelon'))


contacts = {
	'joe':  {'phone': '122-345-0', 'email': 'jo@gjoe.com'},
	'al':   {'phone': '122-390-1', 'email': 'al@gjoe.com'},
	'jack': {'phone': '321-345-6', 'email': 'ja@gjoe.com'}
}
print(contacts['joe']['email'])
print('')

#dict.items() = gave a list of touple an each touple is a value and a key
#dict.keys() = geve a list of just the keys
#dict.values() = gave a list of just the values

#add item write the key in [] and all the other values after the = 
dictionary['strawberry'] = 19
contacts['davide'] = {'phone': '238-224-1', 'email': 'da@gjoe.com'}
print(contacts['davide'])
print(contacts)
print(contacts.popitem())
print('')

#dict.pop('item') = remove the item
print(dictionary)
x_element = dictionary.pop('bananas')
print(dictionary)
print(x_element)#just the value
print('')

#dict.popitem arbitrary element (first one (sometimes))
print(dictionary)
x_element = dictionary.popitem()
print(dictionary)
x_element = dictionary.popitem()
print(dictionary)
x_element = dictionary.popitem()
print(dictionary)
print(x_element)
 
#dict.clear = rimuove tutti gli elementi


#there is a module that keep dictionary ordered
#from collections import OrderedDict
#the order is the orther they are added
#in python 3.7 and later version it is setted by default