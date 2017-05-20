ref ={'E' : 1 ,'W' : -1 , 'N' : 1, 'S': -1}
[t,sx,sy,ex,ey]  = map(int,raw_input().split())
dir = raw_input()
t = 0
cx = sx
cy = sy
flag= 0 
for i in dir :
	if i == 'E' or i == 'W' :
		if (ex - cx) * ref[i] > 0 :
			cx += ref[i]  
	if i == 'S' or i == 'N' :
		if (ey - cy) * ref[i] > 0 :
			cy += ref[i]
	t +=1
	if cx == ex and cy == ey:
		flag = 1
		break 	

if flag == 0:
	print -1
else: 
	print t