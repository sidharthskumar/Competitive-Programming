import math

#[n,k] = map(int, raw_input().strip().split())
#l = map(int, raw_input().strip().split())

n , k  = 70, 10**18
l = [1000]*70 

l = map(lambda x: math.log(x,2) , l)
k = math.log(k,2)

print n , k , l 

prod = []
 
for i in range(n):
	if l[i] <= k:
		leng = len(prod)
		for p in range(leng):
			if prod[p] + l[i] <= k: 
				prod.append(prod[p] + l[i])
		prod.append(l[i])

print len(prod)