c=input()
f=open("outScalar.txt",'w')
for to in xrange(c):
    n=input()
    a=map(int,raw_input().strip().split(" "))
    b=map(int,raw_input().strip().split(" "))
    a.sort()
    b.sort()
    c=b[::-1]
    sum=0
    for i in range(n):
        sum+=a[i]*c[i]
    #print sum
    f.write("Case #" + str(to + 1) + ": " + str(sum) + "\n")
