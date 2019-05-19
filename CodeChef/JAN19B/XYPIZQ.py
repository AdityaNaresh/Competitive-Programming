# cook your dish here
def gcd(x,y): 
    if(y==0): 
        return x 
    else: 
        return gcd(y,x%y)
T=int(input())
for xx in range(T):
    n,t,x,y,z=[int(c) for c in input().split()]
    a=2*n+1
    m=0
    l=0
    if t==2:
        if x>y and y>z:
            g=int(gcd(a,2*n-2*x+3))
            m=int(a/g)
            l=int(2*n-2*x+3)/g
        else:
            g=int(gcd(a,2*n-2*x-1))
            m=int(a/g)
            l=int(2*n-2*x-1)/g
    elif t==1:
        if x>y and y>z:
            g=int(gcd(a,2*n-x+3))
            m=int(a/g)
            l=int(2*n-x+3)/g
        elif x==z:
            g=int(gcd(a,x))
            m=int(a/g)
            l=int(x)/g
        else:
            g=int(gcd(a,2*n-x-1))
            m=int(a/g)
            l=int(2*n-x-1)/g
    elif t==4:
        if x>y and y>z:
            g=int(gcd(a,2*n-2*x+3))
            m=int(a/g)
            l=int(2*n-2*x+3)/g
        else:
            g=int(gcd(a,2*n-2*x-1))
            m=int(a/g)
            l=int(2*n-2*x-1)/g
    elif t==3:
        if x>y and y>z:
            g=int(gcd(a,2*n-x+1))
            m=int(a/g)
            l=int(2*n-x+1)/g
        elif x==z:
            g=int(gcd(a,x))
            m=int(a/g)
            l=int(x)/g
        else:
            g=int(gcd(a,2*n-x+1))
            m=int(a/g)
            l=int(2*n-x+1)/g
    print(str(int(l))+" "+str(m))
