t=int(input())
for xx in range(t):
    n=int(input())
    f=[int(e) for e in input().split()]
    d={}
    sum1=0
    for x in f:
        if x not in d.keys():
            d[x]=1
        else:
            d[x]+=1
    for x in d.values():
        if x>1:
            sum1+=(x-1)
    print(sum1) 
