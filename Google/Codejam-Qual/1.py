f = open("out1.txt", "w")
t = input()

for t0 in range(t):
	[s, k] = raw_input().split()
	k = int(k)
	ans = 0
	ind = 0
	n = len(s)
	flag = 0
	while ind < n: 
		while s[ind] == '+':
			ind += 1
		if ind == n:
			break	
		else if n - ind < k:
			flag = 1
		else:
			for i in range(ind,ind+k):
				if s[i] == '+':
					s[i] = '-'
				else:
					s[i] = '+'



    #f.write("Case #" + str(t0 + 1) + ": " + str(ans % (10**9 + 7)) + "\n")
