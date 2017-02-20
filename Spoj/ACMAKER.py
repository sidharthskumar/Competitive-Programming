n = input()

while n != 0 :
	ref = {}
	for i in range(n):
		ref[input()] = True
	x = raw_input()
	while x != "LAST CASE" :
		l = x.strip().split()
		abbr = l[0]
		words = l[1:]
		curw = 0
		cura = 0
		curc = 0
		flag = True
		state = [[0]*150]*len(abbr)
		for k in words[0]:
			curc += 1
			if k == abbr[0] :
				state[0] += 1
		curw += 1
		cura += 1
		if cura != len(abbr) and curw == len(words) :
			flag = False 
		while curw != len(words) and flag :
			for z in words[curw]:
				if z == abbr[curw]:
					state[curw] +=1
			if state[curw] == 0:
				break	

		if not flag :
			print abbr + " is not a valid abbreviation"
		else :
			print abbr + " can be formed in " + str(state[curc][len(abbr) -1 ]) + " ways"
			