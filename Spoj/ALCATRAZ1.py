t = input()
for i in range(t):
	n = raw_input()
	s = 0
	for x in n:
		s += ord(x)-ord('0')
	print s
