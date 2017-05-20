[a,b,c] = map(int, raw_input().strip().split())
n = input()
l = map(int, raw_input().strip().split())
count = 0
for i in l:
	if b<i<c:
		count += 1
print count