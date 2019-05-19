t=int(input())
for xx in range(t):
    n=int(input())
    a=[int(e) for e in input().split()]
    b=[int(e) for e in input().split()]
    suma=sum(a)
    sumb=sum(b)
    suma-=max(a)
    sumb-=max(b)
    if sumb<suma:
        print("Bob")
    elif suma<sumb:
        print("Alice")
    else:
        print("Draw") 
