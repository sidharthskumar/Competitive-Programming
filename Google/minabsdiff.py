import fileinput
file =fileinput.input(['A-small-practice.in'])
n=file[0]

f = open('outS.txt','w')
cs=1
for x in file:
    ansl = ""
    ansr= ""
    c=x.split(" ")[0]
    j=x.split(" ")[1]
    i=len(c)-1
    while(i>1):
        if(c[i]=='?' and j[i]=='?'):
            if(c[i-1] > j[i-1]):

        elif(c[i]=='?' and c[j]!='?'):
        elif (c[i] != '?' and c[j] == '?'):
        else:
            ansl=c[i]+ansl
            ansr=j[i]+ansr
            i-=1
    f.write("Case #"+str(cs)+": "+ansl+" "+ansr+"\n")
    cs+=1

