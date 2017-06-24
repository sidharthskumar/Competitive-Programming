def R() : return map(int,raw_input().strip().split())
def Rf() : return map(float,raw_input().strip().split())
def Sl() : return raw_input().strip().split()

[n,s] = R()
lo, hi = 1,n+1


while lo < hi:
	sm = 0
	mid = lo + (hi-lo)/2 
	p = mid
	while p != 0:
		sm += p%10
		p /= 10
	if(mid - sm >= s):
		hi = mid
	else:
		lo = mid+1

print (n-lo+1)	