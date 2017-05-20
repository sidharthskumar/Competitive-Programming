[L,d,c]=map(int,raw_input().strip().split(" "))
from itertools import permutations as pm
f=open("outAlien.txt",'w')
pt=[]
for p in range(d):
    pt.append(raw_input())
xt=[]
for to in xrange(c):
    x=raw_input()
    flag=0
    l=[]
    i=0
    while(i< len(x)):
        if(x[i]=='('):
            p=""
            j=i+1
            while(x[j]!=')'):
                p+=(x[j])
                j+=1
            l.append([p,1])
            i=j+1
        else:
            j = i
            while (j<len(x) and x[j] != '('):
                l.append([x[j], 0])
                j += 1
            i = j

    count=0
    for j in pt:
        flag=0
        for i in range(L):
            if(j[i] not in l[i][0]):
                flag=1
        if(flag==0):
            count+=1


    f.write("Case #" + str(to + 1) + ": " + str(count) + "\n")
