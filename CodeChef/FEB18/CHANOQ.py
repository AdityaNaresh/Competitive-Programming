'''
    Brute force Attack!
    Subtask 1 passed
'''
t=int(input())
for rrr in range(t):
    n=int(input())
    l=[]
    for rr in range(n):
        l.append([int(e) for e in input().split()])
    q=int(input())
    for eeee in range(q):
        a=[int(e) for e in input().split()][1:]
        count=0
        for i in l:
            dd=0
            for z in a:
                if z<=i[1] and z>=i[0]:
                    dd+=1
            if dd%2==1:
                count+=1
        print(count)
