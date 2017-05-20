c=input()
f=open("outMilk.txt",'w')
for to in xrange(c):
    n=input()
    m=input()
    mshakes=range(0,n+1)
    
    for i in range(m):
        li=map(int,raw_input().strip().split(" "))
        t=li[0]
        for k in range(0,len(li[1:]),2):
            if(li[k])





    f.write("Case #" + str(to + 1) + ": " + ans + "\n")