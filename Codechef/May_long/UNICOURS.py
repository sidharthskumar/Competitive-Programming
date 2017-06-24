t= input()
for i in range(t):
	n  = input()
	occupied = 0
	a = map(int, raw_input().strip().split())
	for i in range(1,n):
		if occupied < a[i]:
			occupied = a[i]
	print n - occupied
	
