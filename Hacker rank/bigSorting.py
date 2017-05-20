#!/bin/python

import sys


n = int(raw_input().strip())
unsorted = []
unsorted_i = 0
for unsorted_i in xrange(n):
    unsorted_t = str(raw_input().strip())
    unsorted.append(unsorted_t)
# your code goes here

d = len(max(unsorted , key = len))
normalized =[]
for x in unsorted :
	normalized.append('0'*(d - len(x)) + x)

for i in range(d):
	inp = map( lambda x : x[d-1-i] , normalized)
	out = [""]*n
	count = [0]*10
	for j in inp:
		count[ord(j)-ord('0')] +=1
	for i in range(1,10):
		count[i] += count[i-1]
	for i in reversed(range(n)):
		out[count[ord(inp[i])-ord('0')] - 1] = normalized[i]
		count[ord(inp[i])-ord('0')] -=1
	for i in range(n):
		normalized[i] = out[i] 		

for z in normalized:
	k = 0
	while z[k] == '0' and k < d-1:
		k += 1
	print z[k:] 