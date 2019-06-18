t=int(input())
MOD=1000000007
for xxx in range(t):
    n,k = [int(c) for c in input().split()]
    s=0
    if n>=k:
        s=k-1
    else:
        i=((k-1)//(n-1))
        a= ((k-1)%(n-1))
        if i%2==0:
            s = ((((int)(i//2))%MOD)*(((2*a)%MOD+(((((i-1))%MOD)*((n-1)%MOD))%MOD))%MOD))%MOD
        else:
            s = (((i)%MOD)*(((a)%MOD+((((((int)(i-1)//2))%MOD)*((n-1)%MOD))%MOD))%MOD))%MOD
        s += ((k-1)%MOD)
    print((int)(s%MOD))
    
