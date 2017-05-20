[n,s,t] = map(int, raw_input().split())
p = map(int, raw_input().split())
p = [0]+p
count = 0

if s == t :
	print 0
	quit() 
c = p[s]

count +=1
if c == t:
	print 1
	quit()
if c == s :
	print -1
	quit()
while c != s:
	c = p[c]
	count += 1
	if(c == t):
		print count
		quit()
print -1	