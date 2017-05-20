import fileinput
file =fileinput.input(['A-small-practice.in'])
n=file[0]

f = open('outF.txt','w')
ref={0:"ZERO",1:"ONE",2:"TWO",3:"THREE",4:"FOUR",5:"FIVE",6:"SIX",7:"SEVEN",8:"EIGHT",9:"NINE"}
cs=1
cnt={'A':0,'E':0,'F':0,'G':0,'H':0,'I':0,'O':0,'N':0,'R':0,'S':0,'T':0,'U':0,'X':0,'Z':0}
for x in file:
    ans = ""
    for i in ref:
        count=-1
        for j in ref[i]:
            if(count==-1):
                count=x.count(j)
            else:
                if(x.count(j)<count):
                    count=x.count(j)

        if(count>0):
            ans+=str(i)*count
    print ans
    f.write("Case #"+str(cs)+": "+ans+"\n")
    cs+=1