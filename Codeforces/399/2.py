[n,l,r] = map(int, raw_input().strip().split())

x = str(bin(n) [2:])
if(len(x) == 1):
	if(x[0] == '0'):
		print 0
	else :
		print 1
else :
	size = len(x)
	state=[0]*size
	if(x[0] == '1') : 
		state[0] = 1
	for j in range(1,size):
		if(x[j] == '1'):
			state[j] = 2 * state[j-1] + 2
		else :
			state[j] = 2 * state[j-1] + 1
	ans = 0
	print state
	y = str(bin(l-1)[2:])
	z = str(bin(r)[2:])
	y=y + '0'* (size - len(y)) 
	z=z + '0'* (size - len(z)) 
	print y ,z
	for k in range(size):
		if(z[k] == '1'):
			ans += state[k]
		if(y[k] == '1'):
			ans -= state[k]
	print ans


