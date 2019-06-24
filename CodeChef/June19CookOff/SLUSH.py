t=int(input())
for xxx in range(t):
    n,m=[int(c) for c in input().split()]
    c=[int(c) for c in input().split()]
    d=[0]*n
    f=[0]*n
    b=[0]*n
    cd=[0]*m
    for x in range(n):
        p,q,r=[int(c) for c in input().split()]
        d[x]=p-1
        f[x]=q
        b[x]=r
    for x in d:
        cd[x]+=1
    buff=[]
    size=0
    for x in range(m):
        if c[x]<cd[x]:
            size+=cd[x]-c[x]
    for x in range(m):
        if c[x]>cd[x]:
            buff.extend([x]*(c[x]-cd[x]))
            if len(buff)>=size:
                break
    ans=0
    an=[]
    for i in range(n):
        if c[d[i]]>0:
            ans+=f[i]
            an.append(d[i])
            c[d[i]]-=1
        else:
            ans+=b[i]
            an.append(buff.pop())
    print(ans)
    for x in an:
        print(x+1,end=" ")
    print()
