n = input()
a = map(int,raw_input().split())

ans = -1

for i in range(n):
	z = a[i]
	ind = n-1
	while a[ind] != z:
		ind-=1
	curr = 0
	for j in range(i,ind+1):
		curr = curr ^ a[j]
	for j in range(ind+1,n):
		ans = max(curr,ans)
		curr = curr ^ a[j]

  

