n,q=[int(e) for e in input().split()]
a=[int(e) for e in input().split()]
 
for xx in range(q):
    l,r=[int(e) for e in input().split()]
    c=[]
    k=a[l-1:r]
    for x in k:
        c.append("000000000000000000000000000000"+bin(x)[2:])
    ans=''
    k.sort()
    lent=len(bin(k[int(((r-l+1)/2))]))-2
    for x in range(lent):
        count=0
        for y in range(r-l+1):
            if c[y][-x-1]=='1':
                count+=1
        if count>=((r-l+1)/2):
            ans+='1'
        else:
            ans+='0'
    print(2147483647-int(ans[::-1],2)) 
