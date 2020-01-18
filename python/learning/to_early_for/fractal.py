import turtle

line = turtle.Turtle()

def to_early_for_recursion(distance, iter_N):
	if iter_N > 1:
		line.right(45)
		line.forward(distance)
		iter_N = iter_N - 1
		to_early_for_recursion(distance/3, iter_N)
		iter_N = iter_N + 1
		line.right(180)
		line.forward(distance)
		iter_N = iter_N - 1
		to_early_for_recursion(distance/3, iter_N)
		return
	else:
		return



to_early_for_recursion(300, 10)
