def R() : return map(int,raw_input().strip().split())
def Rf() : return map(float,raw_input().strip().split())
def Sl() : return raw_input().strip().split()

n = input()
a = R()
a.sort()
if a[0] == a[1] and a[1]==a[2]:
	x = a.count(a[0])
	print (x*(x-1)*(x-2)/6)
elif a[1] == a[2]:
	x = a.count(a[1])
	print x*(x-1)/2
else:
	x = a.count(a[2])
	print x
