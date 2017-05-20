c=input()
f=open("outA.txt",'w')
for to in xrange(c):
    ans=0
    [l,r]=map(int,raw_input().strip().split(" "))
    x=min(l,r)
    ans=(x*(x+1))/2
    f.write("Case #" + str(to + 1) + ": " + str(ans) + "\n")