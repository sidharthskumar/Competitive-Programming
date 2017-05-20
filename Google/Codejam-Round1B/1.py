t = input()

for t0 in range(t):
	D,N = map(int, raw_input().split())
	ks= []
	for i in range(N):
		[k,s] = map(float, raw_input().split())
		ks.append([k,s])
	ks.sort(key=lambda tup: tup[0])
	over = False
	ans = 1.0
	t = 0
	while not over:
		tmin = 10**10
		ti = -1
		i = 1
		while i < len(ks):
			if ks[i-1][1] ==  ks[i][1] :
				i += 1
				continue
			texp = (ks[i][0]-ks[i-1][0])/(ks[i-1][1] - ks[i][1]) 
			if texp > 0 and texp < tmin and (ks[i-1][0] + ks[i-1][0]*texp < D):
				tmin = texp
				ti = i
			i += 1
		if ti == -1: 
			over = True
			ans = t + (D-ks[0][0])/(ks[0][1]) 
		else:
			t += tmin
			for i in range(ti+1):
				ks[i][0] += ks[i][1]*tmin
			ks[ti-1][1] = min(ks[ti][1],ks[ti-1][1])
			ks = ks[:ti]
	if ans == 0:  print "Case #" + str(t0 + 1) + ":",  ("{0:.6f}".format(0))
	else: print "Case #" + str(t0 + 1) + ":", ("{0:.6f}".format(D/ans))
    