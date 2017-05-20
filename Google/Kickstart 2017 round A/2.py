f= open("out2.txt","w")
t = input()

#[   ] = map(int , raw_input().split())

for t0 in range(t):
	x = raw_input()
	y = raw_input()
	m = len(x)
	n = len(y)
	flag = [ [False for i in range(m+1)] for j in range(n+1)]
	flag[0][0] = True

	ctr = 0
	for i in range(1,m+1):
		if x[i-1] == '*':
			if ctr < 4 :
				flag[0][i] = flag[0][i-1]
				ctr += 1
			else :
				flag[0][i] = False
				ctr = 0
	ctr = 0
	for i in range(1,n+1):
		if y[i-1] == '*':
			if ctr < 4 :
				flag[0][i] = flag[0][i-1]
				ctr += 1
			else :
				flag[0][i] = False
				ctr = 0
	ctrx = 0
	ctry = 0				
	for i in range(1,n+1):
		for j in range(1,m+1):
			if x[j-1] == y[i-1]:
				flag[i][j] = flag[i-1][j-1]
			if x[j-1] == '*':
				if  ctrx < 5 :
					flag[i][j] = flag[i][j-1] or flag[i-1][j]
					ctrx += 1
				else :
					flag[i][j] = False
					ctrx = 0
			if y[i-1] == '*' :
				if  ctry < 5 :
					flag[i][j] = flag[i][j-1] or flag[i-1][j]
					ctry += 1
				else :
					flag[i][j] = False
					ctry = 0

	print flag

	
	#f.write("Case #"+str(t0+1)+": "+ans+"\n")

 	
	