[n,k]=map(int,raw_input().split())
l = map(int,raw_input().split())
i = 0
while(i < min(k,n) and l[i]<0):
	l[i] = -1*l[i]
	i+=1
print sum(l)	
