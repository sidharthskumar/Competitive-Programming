f= open("out1.txt","w")
t = input()

#[   ] = map(int , raw_input().split())
def n_squares(m,n):
	if n < m:
		n , m = m , n
	return ((m-1)*(m)*(2*m-1))/6 + ((n-m)*(m-1)*(m))/2


for t0 in range(t):
	[r,c] = map(int , raw_input().split())
	x = min(r,c)
	ans = 0
	ans += n_squares(r,c)
	i = 3
	while i <  x+1:
		ans += (r-i+1)*(c-i+1)*(i-2)
	
	f.write("Case #"+str(t0+1)+": "+str(ans%(10**9+7)) +"\n")

 	
	