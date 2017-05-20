class AvoidRoads:
	def numWays(self,width ,height,bad):
		flag={}
		s=[([0]*(height+1)) for q in range(width+1)]
		for b in bad:
			flag[b]=True
		s[0][0]=1
		for i in range(width+1):
			for j in range(height+1):
				x=""
				x = x+ str(i-1) + " " +str(j) + " " + str(i) + " " + str(j)
				a= ""
				a = a +  str(i) + " " + str(j) +" " + str(i-1) + " " +str(j) 
				y = ""
				y = y + str(i) + " " + str(j-1) + " " + str(i) + " " + str(j)
				b = ""
				b = b + str(i) + " " + str(j) + " " + str(i) + " " + str(j-1)
				
				 
				if i > 0 and  x not in flag and a not in flag :
					s[i][j] +=(s[i-1][j])
				if j > 0 and y not in flag and b not in flag :
					s[i][j] += (s[i][j-1])
			
		return s[width][height]