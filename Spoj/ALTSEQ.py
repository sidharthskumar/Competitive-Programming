n = input()
a = map(int, raw_input().split())

flag = False
count = 0

dp = [0]* n 
dp[0] = 1

best_yet = 1


for i in range(1,n):
	for j in range(i):
		if abs(a[j]) < abs(a[i]) and dp[i] < dp[j] + 1 and a[i] * a[j] < 0 :
			dp[i] = dp[j] + 1
	print a[j] , a[i]
	if dp[i] > best_yet :
		best_yet = dp[i]


print best_yet