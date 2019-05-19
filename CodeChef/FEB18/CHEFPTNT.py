t=int(input())
for rrr in range(t):
    n,m,x,k=[int(e) for e in input().split()]
    s=input()
    if n > m*x:
        print("no")
    else:
        even_w=sum(["E"==i for i in s])
        odd_w=k-even_w
        even_m=int(m/2)
        odd_m=m-even_m
        total=min(even_w,even_m*x)+min(odd_m*x,odd_w)
        #total=even_m*min(even_w,x)+odd_m*min(x,odd_w)
        #The problem was confusing so i submitted both the solution and the non hashed function passed.
        if n>total:
            print("no")
        else:
            print("yes")
     
