n,m=[int(v) for v in input().split()]
a=[int(v) for v in input().split()]
b=[int(v) for v in input().split()]
x1=min(b)
for y,xx in enumerate(b):
    if xx==x1:
        x1=y
        break
for y,xx in enumerate(a):
    print(str(y)+" "+str(x1))
x=max(a)
#print(x)
for y,xx in enumerate(a):
    if xx==x:
        x=y
        break
#print(x)
for y,xx in enumerate(b):
    if y!=x1:
        print(str(x)+" "+str(y))
