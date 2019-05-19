t=int(input())
for xxx in range(t):
    s=[c for c in input().split()]
    if 'not' in s:
        print("Real Fancy")
    else:
        print("regularly fancy")
