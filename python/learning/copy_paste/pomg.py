import turtle

wn = turtle.Screen()
wn.title("PONG")
wn.bgcolor("black")
wn.setup(width=450, height=600)
wn.tracer(0)


#ball
ball = turtle.Turtle()
ball.penup()
ball.speed(0)
ball.shape("square")
ball.color("white")
ball.dx = 0.1
ball.dy = 0.1

#paddle_a (sx)
p_a = turtle.Turtle()
p_a.penup()
p_a.speed(0)
p_a.shape("square")
p_a.color("white")
p_a.shapesize(stretch_wid=5, stretch_len=1)
p_a.goto(-180, 0)

#paddle_b (dx)
p_b = turtle.Turtle()
p_b.penup()
p_b.speed(0)
p_b.shape("square")
p_b.color("white")
p_b.shapesize(stretch_wid=5, stretch_len=1)
p_b.goto(180, 0)

def a_up():
	p_a.sety(p_a.ycor() + 20)
def a_dawn():
	p_a.sety(p_a.ycor() - 20)

def b_up():
	p_b.sety(p_b.ycor() + 20)
def b_dawn():
	p_b.sety(p_b.ycor() - 20)

wn.listen()
wn.onkey(a_up, "w")
wn.onkey(a_dawn, "s")

wn.onkey(b_up, "Left")
wn.onkey(b_dawn, "Right")

#def op_b():
#	y = 

exit = False
while not exit:
	wn.update()
	
	ball.sety(ball.ycor() + ball.dy)
	ball.setx(ball.xcor() + ball.dx)

	wn.update()

	if(abs(ball.ycor()) + 10 > wn.window_height()/2):
		ball.dy *= -1
	if(ball.xcor() + 10 > p_b.xcor() and ball.ycor() < p_b.ycor() + 50 and ball.ycor() > p_b.ycor() - 50 ):
		ball.dx *= -1
	if(ball.xcor() - 10 < p_a.xcor() and ball.ycor() < p_a.ycor() + 50 and ball.ycor() > p_a.ycor() - 50 ):
		ball.dx *= -1
	
	if(abs(ball.xcor()) > 180):
		ball.goto(0,0)
		exit = True