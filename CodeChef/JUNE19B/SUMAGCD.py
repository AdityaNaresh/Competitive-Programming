def gcd(x, y):
    while y != 0:
        (x, y) = (y, x % y)
    return x
t=int(input())
MOD=1000000007
for xxx in range(t):
    n= int(input())
    a= [int(c) for c in input().split()]
    s=set(a)
    a=list(s)
    a.sort()
    if len(a)==1:
        print(a[0]+a[0])
        continue
    elif len(a)==2:
        print(a[0]+a[1])
        continue
    g=a[0]
    for x in a[1:-2]:
        g = gcd(g,x)
    g1 = gcd(g,a[-2])
    g2 = gcd(g,a[-1])
    print(max(g1+a[-1],g2+a[-2]))
