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
ball.dx = 0.9#velocita' x
ball.dy = 0.13#velocita' y

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

def next_hit(padella):
#spostamento =  vy/vx      *     distanza      
	dy = (ball.dy/abs(ball.dx))*(p_b.xcor()*2)

	#se va verso l'alto
	if (dy > 0):
		#se itta sopra
		if (dy > wn.window_height()/2 - ball.ycor()):
			dy2 = dy - (wn.window_height()/2 - ball.ycor())
			yf = wn.window_height()/2 - dy2
		#se non itta
		else :
			dy2 = dy
			yf = ball.ycor() + dy2
	#se va verso il basso
	else:
		#se itta sotto
		if (dy < -(wn.window_height()/2 + ball.ycor())):
			dy2 = wn.window_height()/2 + (dy + ball.ycor())
			yf = -(wn.window_height()/2 + dy2)
		#se non itta
		else:
			dy2 = dy
			yf = ball.ycor() + dy2

	print(" ".join(["dy =", str(dy),"dy2 =", str(dy2), "yf =", str(yf)]))
	padella.sety(yf)

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
		next_hit(p_a)
	if(ball.xcor() - 10 < p_a.xcor() and ball.ycor() < p_a.ycor() + 50 and ball.ycor() > p_a.ycor() - 50 ):
		ball.dx *= -1
		next_hit(p_b)
	
	if(abs(ball.xcor()) > 180):
		ball.goto(0,0)
		ball.dx *= -1