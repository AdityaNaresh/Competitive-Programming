t=int(input())
for xxx in range(t):
    n,m=[int(c) for c in input().split()]
    l=[[1,1,3,3],[2,2,4,4],[3,3,1,1],[4,4,2,2]]
    h=[[1,1,3,2,2,3],[2,2,3,1,1,3]]
    h2=[[1,2],[1,2],[3,3],[2,1],[2,1],[3,3]]
    if n==1 and m==1:
        print("1")
        print("1")
    elif n==2 and m==2:
        print("2")
        print("2 2")
        print("1 1")
    elif n==1 and m==2:
        print("1")
        print("1 1")
    elif n==2 and m==1:
        print("1")
        print("1")
        print("1")
    elif n==1:
        print("2")
        g=[1,1,2,2]
        for x in range(m):
            print(g[x%4], end=" ")
        print()
    elif m==1:
        print("2")
        g=[1,1,2,2]
        for x in range(n):
            print(g[x%4])
    elif n==2:
        print("3")
        for x in range(n):
            for y in range(m):
                print(h[x][y%6],end=" ")
            print()
    elif m==2:
        print("3")
        for x in range(n):
            for y in range(m):
                print(h2[x%6][y%2],end=" ")
            print()
    elif n>=3:
        print("4")
        for x in range(n):
            for y in range(m):
                print(l[x%4][y%4],end=" ")
            print()
#    elif m==3:
#        print("4")
    # cook your dish here
