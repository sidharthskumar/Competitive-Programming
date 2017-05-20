import math
f = open("out3.txt", "w")
t = input()

for t0 in range(t):
    [N, k] = map(int, raw_input().split())
    part = int(math.pow(2, int(math.log(k, 2))))
    t = N - part + 1
    a  = int(t/part)
    num = t - a  *part
    b = a  + 1
    left = k - part + 1
    if left <= num:
        if b%2 == 0:
            ans = str(int(b/2)) + " " + str(int(b/2)-1)
        else:
            ans = str(int(b/2)) + " " + str(int(b/2))
    else:
        if a %2 == 0:
            ans = str(int(a /2)) + " " + str(int(a /2)-1)
        else:
            ans = str(int(a /2)) + " " + str(int(a /2))


    f.write("Case #" + str(t0 + 1) + ": " + str(ans) + "\n")
