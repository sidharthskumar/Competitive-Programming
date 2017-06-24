# Enter your code here. Read input from STDIN. Print output to STDOUT
def R(): return map(int,raw_input().strip().split())
 
[n ,k ,m]= R()
parent = [i for i in range(n+1)]
rank  = [0]*(n+1)

def find(ind):
	if parent[ind] != ind:
		parent[ind] = find(parent[ind])
	return  parent[ind] 

def union(x ,y):
	sx = find(x)
	sy = find(y)
	if rank[sx] < rank[sy]:
		parent[sx]=sy
	elif rank[sx] > rank[sy]:
		parent[sy]=sx
	else:
		parent[sy]=sx
		rank[sx] += 1

for i in range(k):
    [x,y] = R()
    if find(x) != find(y):
    	union(x,y)

a = R()

L = [[0 for i in range(m)] for i in range(m)]

for i in range(m):
	L[i][i] = 1

for cl in range(2,m+1):
	for i in range(m-cl+1):
		j = i + cl - 1
		if find(a[i]) == find(a[j]) and cl == 2:
			L[i][j] = 2
		elif find(a[i]) == find(a[j]):
			L[i][j] = L[i+1][j-1] + 2
		else:
			L[i][j] = max(L[i][j-1],L[i+1][j])

print L[0][m-1]			
