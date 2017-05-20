n = input()
l = map(int ,raw_input().strip().split())
x=l[0]
y = l[0]
for i in range(1,n):
	if (l[i] < x):
		x = l[i]
	if(l[i] > y):
		y = l[i]


count =0
for i in range(n):
	if l[i] > x and l[i] < y :
		count += 1
print count