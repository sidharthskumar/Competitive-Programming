[n,f] = map(int,raw_input().strip().split())
v= []
a = []
b = []
for i in range(n):
	[c,d] = map(int,raw_input().strip().split())
	v.append((c,d))

v.sort(key = lambda t : t[1],reverse = True)

for i in v:
	if i[0]*2 > i[1]:
		a.append(i)
	else:
		b.append(i)
s= 0
if len(a) >= f:
	for x in range(f):
		s += a[x][1]
	for x in range(f,len(a)):
		s += min(a[x][0],a[x][1])
	for x in range(len(b)):
		s += min(b[x][0],b[x][1])	
else:
	b.sort(key = lambda t : t[0] , reverse=True)
	for x in range(len(a)):
		s += a[x][1]
	for x in range(f-len(a)):
		s += b[x][0]*2
	for x in range(f -len(a),len(b)):
		s += min(b[x][0],b[x][1])	

print s