[n,s,t] = map(int, raw_input().strip().split())
[r0,g,sd,p] = map(int, raw_input().strip().split())

ind = s
r  = []
r.append(r0)
for i in range(n-1):
	r.append((r[-1]*g+sd)%p)

l = set()

flag = False
dist = 0

for i in range(1,r[s]+1):
	l.add(((s- i)%n,0))
	l.add(((s + i)%n,0))

.remove