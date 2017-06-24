def R() : return map(int,raw_input().strip().split())
def Rf() : return map(float,raw_input().strip().split())
def Sl() : return raw_input().strip().split()


[x,y,l,r] = R()

mx = -1

a = [1]
b = [1]
c = []

pa = 1
pb = 1

while a[-1] < r:
	a.append(a[-1]*x)
a.pop()

while b[-1] < r:
	b.append(b[-1]*y)
b.pop()

for x in a:
	for y in b:
		if l<=x+y <=r:
			c.append(x+y)
c.sort()
if len(c)==0:
	print r - l +1
else:
	if c[0] - l > mx : mx = c[0] - l 
	if r - c[-1]  > mx : mx = r - c[-1] 
	for i in range(1,len(c)):
		if c[i] - c[i-1] - 1> mx : mx = c[i] - c[i-1] -1
	print mx	