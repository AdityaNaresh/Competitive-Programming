def fun(a,n):
    s=a[n-1][0]
    i=n-2
    lastmax=s
    while i!=-1:
        if min(a[i])>=lastmax:
            return -1
        else:
            for f in a[i]:
                if f<lastmax:
                    s+=f
                    lastmax=f
                    break
        i-=1
    return s
t=int(input())
for q in range(t):
    n=int(input())
    a=[]
    for x in range(n):
        a.append([int(e) for e in input().split(" ")])
        a[x]=list(set(a[x]))
        a[x].sort(reverse=True)
    print(fun(a,n))
