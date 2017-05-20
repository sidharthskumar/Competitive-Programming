s=""
def swap(s):
    for i in s:
        if(i=='0'):
            i='1'
        else:
            i='0'
def reverse(s):
    x=""
    for i in reversed(s):
       x.append(i)
for i in range(0,pow(10,100)):
    s=s+"0"+swap(reverse(s))

print s