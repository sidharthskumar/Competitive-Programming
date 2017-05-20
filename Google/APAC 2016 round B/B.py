c=input()
f=open("outB.txt",'w')
for to in xrange(c):
    ans=0
    [a,b,n,k]=map(int,raw_input().strip().split(" "))
    for i in range(1,n+1):
        for j in range(1,i)+range(i+1,n+1):
            if(pow(i,a,k)+pow(j,b,k) in [0,k,2*k]):
                ans+=1
    ans=ans%(10**9+7)
    f.write("Case #" + str(to + 1) + ": " + str(ans) + "\n")