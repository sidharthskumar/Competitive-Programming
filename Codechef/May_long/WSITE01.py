class alphaNode:
	def __init__(self,alpha,sym):
		self.aplha = alpha
		self.children = [None]*26
		self.blocked = sym   
class alphaTree:
	def __init__(self):
		self.root = [None]*26

	def insert_string(self,string,sym):
		curr = self.root
		key = 0
		while key < len(string):	
			if not curr[ord(string[key]) - ord('a')-1]:
				curr[ord(string[key]) - ord('a')-1] = alphaNode(string[key],sym)
			else:
				curr = curr[ord(string[key]) - ord('a')-1].children
				key += 1
n = input()
alpha = alphaTree()
later = []
for i in range(n):
	[sym, s] = raw_input().strip().split()
	if sym == '-':
		later.append(s)
	else:
		alpha.insert_string(s,False)

for s in later:
	alpha.insert_string(s,True)

filters	= set()
possible = True
for string in later:
	key = 0
	curr = alpha.root
	while key < len(string) and not curr[ord(string[key]) - ord('a')-1].blocked:
		curr = curr[ord(string[key]) - ord('a')-1].children
		key += 1
	if key == len(string):
		possible = False
		break
	else:	
		filters.add(string[:key+1])

if not possible:
	print -1
else:
	final_filters  = sorted(list(filters))
	print len(final_filters)
	for i in final_filters:
		print i	


