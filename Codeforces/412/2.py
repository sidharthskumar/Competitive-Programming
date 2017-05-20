[p, x, y] = map(int, raw_input().strip().split())

def check(key,score):
	tshits = []
	t = (score//50) % 475
	for j in range(25):
		t = ((t * 96) + 42) % 475
		tshits.append(26 + t)
	if key in tshits:
		return True
	else:
		return False
flag = False
sc = x
nsc = x
negFlag = False
while nsc >= y:
	if check(p,nsc):
		print 0
		negFlag = True
		break
	else:
		nsc -= 50
if not negFlag:
	while not flag:
		if check(p,sc):
			print math.ceil(sc-x)/100
			flag = True
		else:
			sc = sc+50

