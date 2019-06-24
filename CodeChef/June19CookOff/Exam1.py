t=int(input())
for xxx in range(t):
    n=int(input())
    s=input()
    u=input()
    c=0
    i=0
    while i<n:
        if s[i]==u[i]:
            c+=1
        elif u[i]=='N':
            i+=1
            continue
        else:
            i+=1
        i+=1
    print(c)
