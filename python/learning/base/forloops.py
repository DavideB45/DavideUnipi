import turtle

pen = turtle.Turtle()
pen.color("green")
pen.speed(100)
pen.left(135)
pen.forward(500)
pen.right(135)

def square(dim):
	for count in range(4):
		pen.forward(dim)
		pen.right(90)
		count = count#per non vederlo giallo

for i in range(75):
	square(i*10)

count = raw_input()