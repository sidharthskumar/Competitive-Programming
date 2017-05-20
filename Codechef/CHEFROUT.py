t = input()
for i in range(t):
	s =raw_input()
	ind =0
	n = len(s)
	while ind <n and s[ind] == 'C':
		ind+=1
	while ind <n and s[ind] == 'E':
		ind+=1
	while ind <n and s[ind] == 'S':
		ind+=1 

	if ind != n:
		print "no"
	else:
		print "yes"