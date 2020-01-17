from math import *


class animal():
	def __init__(self):
		print "animal"
	def move(self):
		print "move"

class dog(animal):
	def __init__(self):
		print "class"


def myFunc(arg1):
	myString = "culo"
	myList = [1, 3, 5, 6, 1, 2, 4, 5, 2, 3, 4, 5]
	print dir(myString)

def main():
	print "Hello David !"
	myFunc(True)

if __name__ == "__main__" :
	main()
# F5 debug