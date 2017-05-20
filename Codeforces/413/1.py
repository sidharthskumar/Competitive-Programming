[n,t,k,d] = map(int, raw_input().strip().split())

without_new = 0
with_new = d

if n%k == 0:
	without_new = t * (n//k)
else:
	without_new = t * (n//k) + t 

remain = n - (((d//t)+1)*k)


flag = True
if remain <= 0:
	flag = False

if remain%k == 0:
	with_new += t
	remain = remain - k
	if remain > 0:
		with_new += t * (remain//(k*2))
		
else:
	with_new += t
	remain = remain - k
	if remain > 0:
		with_new += t * (remain//(k*2)) + t
	
if with_new < without_new and flag:
	print "YES"
else:
	print "NO"