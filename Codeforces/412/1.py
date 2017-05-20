n = input()
l = []
for i in range(n):
	[a, b] = map(int, raw_input().strip().split())
	l.append((a,b))
flagChanged = False
flagOrder = False
if l[0][0]!= l[0][1]:
	flagChanged = True
for i in range(1,n):
	if l[i][0] != l[i][1]:
		flagChanged = True
	elif l[i][0] > l[i-1][0]:
		flagOrder = True
if flagChanged:
	print "rated"
elif flagOrder:
	print "unrated"
else:
	print "maybe"  