t=input()
f=open('outStore.txt',mode='w')
for to in xrange(t):
    n=input()
    a=[0]*n
    b=[0]*n
    check={}
    count=0
    w=100
    for i in range(n):
        [a[i],b[i]]=map(int,raw_input().strip().split(" "))
        for j in range(a[i],b[i]+1):
            if(b[i]!=a[i]):
                if((w*j)/(b[i]-a[i]),j) not in check:
                    check[((w*j)/(b[i]-a[i]),j)]=1
                else:
                    check[((w*j)/(b[i]-a[i]),j)]+=1
            else:
                for i in range(1,100):
                    if (i, j) not in check:
                        check[(i,j)] = 1
                    else:
                        check[(i,j)] += 1

    print check[max(check, key=check.get)]-1