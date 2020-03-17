import turtle

turtle.bgcolor("black")
X = turtle.Turtle()

def draw_right(pen, space):
	pen.right(45)
	pen.forward(space)

def draw_left(pen, space):
	pen.left(90)
	pen.forward(space)
	
def draw(pen, lenght, time):
	if(time > 0):
	####destra
		#pen.color("black")
		draw_right(pen, lenght)
		draw(pen, lenght/1.5, time - 1)
	####indietro_dx
		#pen.color("blue")
		pen.back(lenght)
	####sinistra
		#pen.color("black")
		draw_left(pen, lenght)
		draw(pen, lenght/1.5, time - 1)
	####indietro_sx
		#pen.color("green")
		pen.back(lenght)
		pen.right(45)


X.color("white")
X.speed("fastest")

draw(X, 100, 10)
X.right(180)
draw(X, 100, 10)


p = input()