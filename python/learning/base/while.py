#include turtle

import turtle

arrow = turtle.Turtle()
arrow.color("green")

somewone = True
i = 0
while somewone:
	i = i + 1
	arrow.forward(20)
	arrow.right(90)
	if i == 100:
		somewone = False