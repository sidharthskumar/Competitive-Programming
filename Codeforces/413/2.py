n = input()
p = map(int, raw_input().strip().split()) 
a = map(int, raw_input().strip().split())
b = map(int, raw_input().strip().split())
m = input()
c = map(int, raw_input().strip().split())

z = list(enumerate(p))
f = zip(z,a,b)
f.sort(key=lambda i:i[0][1])
last = [0] * (3)
taken = [False]*n
for k in c:
	while last[k-1] < n and (taken[f[last_one][0][0]] or (f[last[k-1]][1] != k and f[last[k-1]][2] != k )) :
		last[k-1] += 1
	if last[k-1] != n:
		print f[last[k-1]][0][1] ,
		taken[f[last[k-1]][0][0]] = True
		last[k-1] += 1
	else:
		print -1 , 

