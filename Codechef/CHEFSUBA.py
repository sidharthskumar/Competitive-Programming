def print_array():
	start, end = (0 - shift_count)%n ,n - shift_count 
	if start < end:
		for i in range(start,end):
			print a[i] , 
		print
	else:
		for i in range(start,n) + range(0,end):
			print a[i] , 
		print
 
def get_max():
	max_ones = 0
	max_temp = first_ones
	if max_temp > max_ones:
		max_ones = max_temp
	start , end = (k-shift_count)%n, (n - shift_count)%n	
	if start < end:	
		for i in range(start,end):
			if a[(i-k)%n] != 1:
				if a[i] == 1:
					max_temp += 1
			elif a[i] != 1:
				max_temp -= 1
			if max_temp > max_ones:
				max_ones = max_temp
	else:
		for i in range(start,n) + range(0,end):
			if a[(i-k)%n] != 1:
				if a[i] == 1:
					max_temp += 1
			elif a[i] != 1:
				max_temp -= 1
			if max_temp > max_ones:
				max_ones = max_temp
					
	return max_ones
 
[n,k,p] = map(int, raw_input().strip().split())
a = map(int, raw_input().strip().split())
b = raw_input()
 
if k > n:
	k = n
first_ones = 0
max_ones = 0
for i in range(k):
	if a[i] == 1:
		first_ones += 1
 
shift_count = 0		
max_ones = get_max()
 
for i in b:
	if i == '?':
		print max_ones
	else:
		shift_count = (shift_count + 1)%n
		if a[(n - shift_count + k)%n] != 1:
			if a[(n-shift_count)%n] == 1:
				first_ones += 1
		elif a[(n-shift_count)%n] != 1:
			first_ones -= 1
		if a[(n - shift_count)%n] == 1:
			max_ones = get_max()