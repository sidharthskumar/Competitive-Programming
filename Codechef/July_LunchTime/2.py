def allset(num):
    if num == 0:
        return False
    return (num & (num+1)) == 0

t = input()
for to in range(t):
    n = input()
    a = map(int,raw_input().strip().split())
    ans = 0
    for i in range(0,n-1):
        for j in range(i+1,n):
            if a[i] == a[j] || allset(a[i]) || allset(a[j]):
                ans += 1
    print ans
