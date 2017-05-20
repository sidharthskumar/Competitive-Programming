n = input()
new = 1
colors = [0]*(n+2)
for i in range(2,n+2):
	for j in range(i,n+2,i):
		if colors[j]==0 :
			colors[j] = new
			if j + i < (n+2) or not (i < n+1 and j%(i+1) != 0):
				new += 1
print new
for i in colors[2:]:
	print i ,
