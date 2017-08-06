t = input()
for i in range(t):
    a = map(int,raw_input().strip().split())
    n = len(a) - 1
    cnt = 0
    mx = 1
    for el in a:
        if el == n:
            cnt += 1
        else :
            mx = max(mx,el)
    if cnt == 1:
        print mx
    else:
        print max(mx,n)
