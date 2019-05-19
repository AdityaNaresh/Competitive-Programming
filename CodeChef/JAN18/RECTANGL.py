t=int(raw_input())
while t!=0:
    t-=1
    a,b,c,d=[int(e) for e in raw_input().split(" ")]
    count=0
    if a==b:
        if c==d:
            count+=1
    if a==c:
        if b==d:
            count+=1
    if a==d:
        if c==b:
            count+=1
    if count!=0:
        print("YES")
    else:
        print("NO")
