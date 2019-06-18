t=int(input())
MOD=1000000007
for xxx in range(t):
    n= int(input())
    s=5*pow(2,n,MOD)
    print((int)(s%MOD))
    
