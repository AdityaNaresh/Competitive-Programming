t=int(input())
for xxx in range(t):
    n=int(input())
    ans = n*10
    su=0
    while (n!=0):
        su+= n%10
        n=n//10
    su%=10
    print(ans+(10-su)%10)
