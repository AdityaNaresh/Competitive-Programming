def loss(f,g,x):
    return g*(f-((100-x)/100)*(f+f*(x/100)))
t=int(input())
for xx in range(t):
    n=int(input())
    sum1=float(0)
    for xxx in range(n):
        f=[int(e) for e in input().split()]
        sum1+=loss(f[0],f[1],f[2])
    print(abs(sum1)) 
