import math
t= int(input())
for xxxx in range(t):
    d=int(input())
    s=input()
    c=0
    t=0
    m=0.75*d
    for x in s:
        if x=="P":
            t+=1
    for i in range(2,d-2):
        if ((s[i]== 'A') and (s[i-2]=='P' or s[i-1]=='P') and (s[i+1]=='P' or s[i+2]=='P')):
            c+=1
    if ((c+t)<m):
        print("-1")
    elif t>=m:
    	print("0")
    else:
        print(math.ceil(m-t))
