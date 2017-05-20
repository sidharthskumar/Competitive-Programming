t=input()
f=open('outStore.txt',mode='w')
for to in xrange(t):
    c=input()
    i=input()
    l=map(int,raw_input().strip().split(" "))
    for a in range(i-1):
        flag=0
        for b in range(a+1,i):
            if(l[a]+l[b]==c):
                f.write("Case #"+str(to+1)+ ": " + str(a+1) +" "+ str(b+1) +"\n")
                flag=1
                break
        if(flag==1):
            break