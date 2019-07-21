t=int(input())
for xxx in range(t):
    a=[0]*1000000
    l=[]
    e=0
    o=0
    q=int(input())
    for xx in range(q):
        k=int(input())
        if a[k]==0:
            a[k]=1
            lt=[]
            lt.append(k)
            for c in l:
                z=k^c
                lt.append(z)
                a[z]=1
            l.extend(lt)
            ss = bin(k).count('1')
            if ss%2==0:
                e = (e*2) + 1
                o = o*2
            else:
                e = e+o
                o = e+1
        print("%d %d"%(e,o))
        
