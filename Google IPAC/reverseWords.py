t=input()
f=open("outReverse.txt",'w')
for to in xrange(t):
    x= raw_input()
    res=""
    i=0
    j=0
    while(j <=len(x)):
        while i< len(x) and  x[i]!=" " :
            i+=1
        res=x[j:i]+" "+res
        j=i+1
        i+=1
    f.write("Case #"+str(to+1)+": "+res +"\n")