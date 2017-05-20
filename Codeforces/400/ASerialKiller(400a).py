[a , b] = raw_input().split()
n = input()
print a, b
for i in range(n):
	[x ,y] = raw_input().split()
	if x == a :
		a = y
		print  y , b
	elif x == b :
		b = y
		print  y , a


