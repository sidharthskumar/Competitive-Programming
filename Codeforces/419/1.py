def R() : return map(int,raw_input().strip().split())
def Rf() : return map(float,raw_input().strip().split())
def Rs() : return raw_input().strip().split()

x = raw_input()
[a,b] = x.split(':')
ans = 0
if "00" <= a <= "05":
	if b <= a[::-1]:
		ans = (ord(a[::-1][0]) - ord('0'))*10 + (ord(a[::-1][1])-ord('0')) - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0'))
	elif a == "05":
		ans = 241 + (60 - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0')))
	else:
		ans = (60 - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0'))) + (ord(a[::-1][0]) - ord('0'))*10 + (ord(a[::-1][1]) - ord('0')) + 10 
elif "06" <= a <= "10":
	if a != "10":
		ans = (61 - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0'))) + (9 - (ord(a[1]) - ord('0')))*60
	elif b == "00":
		ans = 1
	elif b == "01":
		ans = 0
	else:
		ans =  (71 - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0')))     
else:
	if a != "23":
		if b <= a[::-1]:
			ans = (ord(a[::-1][0])- ord('0'))*10 + (ord(a[::-1][1]) - ord('0')) - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0'))
		else:
			ans = (60 - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0'))) + (ord(a[::-1][0]) - ord('0'))*10 + (ord(a[::-1][1]) - ord('0')) + 10
	else:
		if b <= "32":
			ans = 32 - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0'))
		else:
			ans = (60 - ((ord(b[0]) -ord('0'))*10 + ord(b[1]) -ord('0')))
print ans