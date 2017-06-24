def R() : return map(int,raw_input().strip().split())
def Rf() : return map(float,raw_input().strip().split())
def Rs() : return raw_input().strip().split()

n = input()
a = R()
m = input()
l = [R() for i in range(m)]

done = False
for x in l:
	if x[0] > sum(a) :
		print x[0]
		done = True
		break
	if x[0] <= sum(a)  <= x[1]:
		print sum(a)
		done = True
		break

if not done:
	print -1