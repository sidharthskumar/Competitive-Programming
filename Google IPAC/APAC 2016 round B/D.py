c=map(int,raw_input().strip().split(" "))
f=open("outD.txt",'w')
for to in xrange(c):
    n=input()
    ans=0
    l=map(int,raw_input().strip().split(" "))

    f.write("Case #" + str(to + 1) + ": " + str(ans) + "\n")