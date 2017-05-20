a = sorted(list(raw_input().strip()))
b = sorted(list(raw_input().strip()))
n = len(a)

i , j = 0 , n-1
ans = ""
count = 0
while True:
	if count < n:
		if a[i] <= b[j]:
 			ans += a[i]
 		else:
 			ans = a[n-i-1] + ans	
 		i += 1
 		count += 1
 	else:	
 		break
 	if count < n:
 		if b[j] >= a[i]:
 			ans += b[j]
 		else:
 			ans = b[j] + ans
 		j -= 1 
		count += 1
 	else:
 		break

print ans
