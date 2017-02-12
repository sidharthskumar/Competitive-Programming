c=input()
f=open("outC.txt",'w')
def cov(l):
    s=0
    for i in range(len(l)-1):
        s+=l[i][1]-l[i][0]
        for j in range(i+1,len(l)):
            if(l[j][0]<l[i][1] and l[j][0]>l[i][0]):
                if(l[j][1]>l[i][1]):
                    s+=l[j][1]-l[i][1]

    return s
for to in xrange(c):
    ans=0
    [n,l1,r1,a,b,c1,c2,m]=map(int,raw_input().strip().split(" "))
    l=[0]*n
    r=[0]*n
    cv=[]
    l.append(l1)
    r.append(r1)
    for i in range(1,n):
        x=(a*l[i-1]+b*r[i-1]+c1)%m
        y=(a*r[i-1]+b*l[i-1]+c2)%m
        if(x<y):
            l[i]=x
            r[i]=y
        else:
            l[i] = y
            r[i] = x
    ref=[]
    for i in range(len(l)):
        ref.append((l[i],r[i]))
    print ref
    ref=list(set(ref))
    min=10**10
    for i in range(len(ref)):
        if(cov(ref[:i]+ref[i+1:])<min):
            min=cov(ref[:i]+ref[i+1:])
    print min
    f.write("Case #" + str(to + 1) + ": " + str(min) + "\n")