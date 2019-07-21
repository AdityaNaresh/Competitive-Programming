t=int(input())
for xxx in range(t):
    n=int(input())
    a=[int(c) for c in input().split()]
    s=sum(a)
    avg = s/n
    flag = True
    for i in range(n):
        if a[i]==avg:
            print(i+1)
            flag = False
            break
    if flag:
        print("Impossible")
