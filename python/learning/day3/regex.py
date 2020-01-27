#regular expression
import re
#way to specify pattern in string and text
#automi?

#example email address
text = "this is a string"

#this is what it will research as pattern
#in ths case it will look for the whole phrase
#                        |
#                        V
pattern = re.compile("this is a string")
result = pattern.search(text)
#ersult is an object not a clear result :(
print(result)

pattern = re.compile('[ABC]')
#'[ABC]' is or
#'[a-d]'
#'[a-z]+'chiusura di Clini oppure l'altra non lo so (quella senza la stringa vuota)
#ceck the escape if something is nt working
result = pattern.search(text)
print(result)

#email : '[a-zA-Z0-9._-]+@[a-zA-Z0-9]+\.com'
#riconosce un' email cercando il pattern sopra
text = 'email-vera.88@coso.net'
pattern = re.compile('[a-zA-Z0-9._-]+@[a-zA-Z0-9]+.(it|com|net)')
result = pattern.search(text)
if result != None:
	print(result.string)
else:
	print("Not found")