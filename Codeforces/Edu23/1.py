def R() : return map(int,raw_input().strip().split())
def Rf() : return map(float,raw_input().strip().split())
def Sl() : return raw_input().strip().split()

[x1,y1,x2,y2] = R()
[x,y] = R()
if(abs(x2-x1)%x == 0 and abs(y2-y1)%y==0 and (abs(y2-y1)/y+ abs(x2-x1)/x)%2==0):
	print "YES"
else:
	print "NO"
