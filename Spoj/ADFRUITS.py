import sys

for z in sys.stdin:
	[a,b] = z.split()
	[m, n] = len(a) , len(b)
	x = [False] * len(a)
	y = [False] * len(b)

	l = [ [0 for i in range(n+1)] for j in range(m+1)]
	for i in range(m+1):
		for j in range(n+1):
			if i == 0 or j == 0 :
				l[i][j] = 0
			elif a[i-1] == b[j-1] :
				l[i][j] = l[i-1][j-1] + 1
			else :
				l[i][j] = max(l[i-1][j] ,l[i][j-1])

	p ,q = m ,n			
	while p > 0 and q > 0:
		if a[p-1] == b[q-1]:
			x[p-1] = True
			y[q-1] = True
			p -= 1
			q -= 1
		elif l[p-1][q] > l[p][q-1] :
			p -= 1 
		else :
			q -= 1
	
	ans = ""
	i , j = 0 , 0 
	while i != m or j != n :
		while i < m and not x[i] :
			ans += a[i]
			i += 1
		while j < n and not y[j] :
			ans += b[j]
			j += 1
		if i < m and j < n :
			ans += a[i]
			i += 1
			j += 1


	print ans 


