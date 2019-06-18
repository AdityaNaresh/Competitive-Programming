t=int(input())
for xxx in range(t):
    n=int(input())
    a=[int(c) for c in input().split()]
    k=int(input())
    x=int(input())
    s=sum(a)
    d=[int((c^x)-c) for c in a]
    if k==n:
        if sum(d)>0:
            s+=sum(d)
    else:
        d.sort(reverse = True)
        p=sum([int(c>0) for c in d])
        if p%2==0:
            s+=sum([int(c*((int)(c>0))) for c in d])
        elif k%2==1:
            s+=sum([int(c*((int)(c>0))) for c in d])
        elif k%2==0:
            n1=0
            n2=0
            for i in range(n):
                if d[i]<=0:
                    n1=d[i-1]
                    n2=d[i]
                    break
            #print(n1,n2)
            s+=sum([int(c*((int)(c>0))) for c in d])
            s=max(s+n2,s-n1)
            if p==n:
                s-=d[-1]
    print(s)
    #print(sum(a))
    #print(d)
            
