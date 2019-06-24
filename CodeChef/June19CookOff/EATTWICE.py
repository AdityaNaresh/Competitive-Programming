t=int(input())
for xxx in range(t):
    n,m=[int(c) for c in input().split()]
    d=[0]*m
    for xx in range(n):
        a,b=[int(c) for c in input().split()]
        d[a-1]=max(d[a-1],b)
    largest = d[0]  
    largest2 = None
    for item in d[1:]:      
        if item > largest:  
            largest2 = largest 
            largest = item  
        elif largest2 == None or largest2 < item:  
            largest2 = item  
    print(largest2+largest)
    
    
