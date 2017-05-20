import math
t = input()
for i in range(t):
	[x,y,p,q] = map(float, raw_input().strip().split())
	org_y = y
	if p == 0:
		if x == 0:
			print 0
		else:
			print 1
	elif p==q:
		if x!= y:
			print -1
		else:
			print 0
	else:
		while abs(x/y - p/q) > 0.000001:
			if (x/y > p/q) :
				y += math.ceil((x*q-p*y)/p)
			elif(x/y < p/q):
				x += math.ceil((p*y-x*q)/(q-p))
				y += math.ceil((p*y-x*q)/(q-p))

		if abs(x/y - p/q) < 0.000001:
				print int(y - org_y)
					