def compare(f,g):
    for x,y in zip(f,g):
        if x>y:
            return False
    return True
t=int(input())
for xx in range(t):
    n=int(input())
    f=[int(e) for e in input().split()]
    g=[int(e) for e in input().split()]
    a=compare(f,g)
    b=compare(f,g[::-1])
    if a and b:
        print("both")
    elif a:
        print("front")
    elif b:
        print("back")
    else:
        print("none") 
