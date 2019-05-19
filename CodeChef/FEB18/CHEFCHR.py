t=int(input())
for e111111 in range(t):
    s1=input()
    c2=False
    count=0
    for i in range(len(s1)-3):
        z=[s1[i]]
        z.append(s1[i+1])
        z.append(s1[i+2])
        z.append(s1[i+3])
        if 'c' in z and 'h' in z and 'e' in z and 'f' in z:
            count+=1
            c2=True
    if c2==True:
        print("lovely",count)
    else:
        print("normal") 
