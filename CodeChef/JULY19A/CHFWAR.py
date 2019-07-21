a=[]
def fun(n,p,ans):
    d=0
    ap1f=0
    ap1l=p-1
    ap1len=p
    ap2l=n-1
    ap2len=n-p
    apcd=1
    flag=True
    if ans==-1:
        flag=False
    while(not(ap1len==0 and ap2len==1)):
        #print(d)
        if not (ap2len>2 and ap1len==0):
            if ap1len%2 ==0:
                ap1l-=apcd
                ap1len=ap1len//2
            else:
                d+=a[ap1l]
                if(flag and d>ans):
                    return d
                ap1len=((ap1len+1)//2)
            if ap2len%2==0:
                ap2l-=apcd
                apcd*=2
                ap2len=ap2len//2
            else:
                apcd*=2
                ap1f+=(apcd)
                ap1len-=1
                ap2len=((ap2len+1)//2)
        else:
            if ap2len%2 == 0:
                ap2l-=apcd
                apcd*=2
                ap2len=ap2len//2
            else:
                d+=a[ap2l]
                if(flag and d>ans):
                    return d
                apcd*=2
                ap2len=((ap2len+1)//2)
    #print(p)
    return d

def mainfun(n,f):
    ans=-1
    p=-1
    for i in range(n):
        if a[i]<=f:
            temp=fun(n,i,ans)
            if ans == -1 or temp<ans:
                ans=temp
                p=i
    
    print("%d %d"%(p+1,ans+f))

t=int(input())
for xxx in range(t):
    n=int(input())
    a=([int(c) for c in input().split()])
    f=int(input())
    flag=True
    for x in a:
        if(x<=f):
            flag=False
            break
    if flag:
        print("impossible")
    else:
        print("possible")
        mainfun(n-1,f)
