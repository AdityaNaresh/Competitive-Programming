import math
t=int(input())
for xx in range(t):
    n,p=[int(c) for c in input().split()]
    if n<=2:
        print(p**3)
    else:
        a=int(math.ceil(n/2)-1)
        ans=(p-a)*(p-n)+(p-n)**2+(p-a)**2
        print(ans)
