def dfs(i):
	vis[i] = True
	for x in ref[i]:
		if not vis[i]:
			dfs(x)

global ref
[n,m] = map(int, raw_input().split())
ref = {};
for i in range(max(n,m+1)):
	ref[i]=[]
global vis
vis = [False]*(n+1)
count =0
for i in xrange(n):
	l= map(int, raw_input().split())
	l.pop(0)
	for x in l:
		ref[i].append(x)
		ref[x].append(i)
print ref
for j in range(1,n+1):
	if not vis[j]:
		dfs(j)
		count += 1
print count