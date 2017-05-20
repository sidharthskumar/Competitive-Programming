n = input()
c = 1
ans = 1

[h,m] = map(int,raw_input().split())
for i in range(n-1):
	[x,y] = map(int,raw_input().split()) 
	if x==h and y==m :
		c +=1
	else:
		ans = max(ans,c)
		c =1	
	h , m = x ,y	
ans = max(ans,c)
print ans