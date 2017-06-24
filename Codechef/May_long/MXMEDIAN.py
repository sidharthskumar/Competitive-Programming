t = input()

for to in range(t):
	n = input()
	a = map(int, raw_input().strip().split())
	a.sort()
	i = 0
	j = 2*n -1;
	l = []
	b = []
	while i < j:
		l.append(a[i])
		l.append(a[j])
		b.append(max(a[i],a[j]))
		i += 1
		j -= 1

	b.sort()
	print b[n//2]

	for i in l:
		print i, 
	print
		

