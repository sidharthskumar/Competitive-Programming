def answer(s):
    result=1
    if len(s)==1:
        return result

    if s[0]!=s[1]:
        result*=2

    for i in range(1,len(s)-1):
        if s[i-1]==s[i] and s[i]!=s[i+1]:
            result*=2
        elif s[i-1]!=s[i] and s[i]==s[i+1]:
            result*=2
        elif  s[i-1]==s[i+1] and s[i]!=s[i-1]:
            result*=2
        else:
            result*=3

    if s[-1]!=s[-2]:
        result*=2


    return result

no=input("")
answers=[]
for i in range(no):
    string=raw_input("")
    p=answer(string)
    answers.append(p)


for k in range (no):
    print "case #%d %d"%(k+1,answers[k])

