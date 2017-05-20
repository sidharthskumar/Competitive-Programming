class FlowerGarden:
	def getOrdering(self, height, bloom ,wilt) :
		fls = zip ( height , bloom ,wilt)
		fls.sort()
		
		def check(ab ,aw ,bb, bw):
			return ab <= bw and bb <= aw
		ans= []
		for i in fls:
			j = len(ans)
			
			while  j > 0 and not check(i[1],i[2],ans[j-1][1],ans[j-1][2]) :
				j -= 1
			ans.insert(j,i)
		return [x[0] for x in ans]