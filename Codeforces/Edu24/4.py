[n,a] = map(int,raw_input().strip().split())
c = map(int,raw_input().strip().split())
first = set()
inx = []
ind = 0
cnt = [0]*1000001
for i in range(n):
	if c[i] == a:
		inx.append(i)
if len(inx) == 0:
	print c[0]
else:
	while ind != inx[0]:
		first.add(c[ind])
		cnt[c[ind]]+=1
		ind += 1
	ind += 1
	if len(inx) > 1:
		for p in range(1,len(inx)):
			second = set()
			while ind != inx[p]:
				second.add(c[ind])
				cnt[c[ind]]+=1
				ind += 1
			ind += 1
			for el in list(first):
				if(cnt[el] < p+1 and el not in second):
					first.remove(el)
	if len(first) == 0:
		print -1
	else:
		print list(first)[0]




