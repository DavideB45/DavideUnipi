l = (1,2,3)
#non si possono aggiungere / togliere elementi

person7 = ("nando", 25, "pizza")
#OCaml style
#le parentesi non sono neccessarie
#(name, age, favfood) = person7
#print(name)
#print(age)
#print(favfood)

person1 = ("mist", 20, "ananas")
person2 = ("cartuccio", 30, "salame")
person3 = ("armando", 2, "plastica")
population = [person1, person2, person3, person7]

for name, age, favfood in population:
	print(name)
	print(age)
	print(favfood)
	print('')