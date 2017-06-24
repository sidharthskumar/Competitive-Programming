import math
[a,b] = map(float,raw_input().split())
n = 1
while True:
 	if(a < (2*n-1)):
 	   print "Vladik"
 	   break
 	a -= (2*n-1)
 	if(b < 2*n):
 		print "Valera"
 		break
 	b -= 2*n
 	n += 1



