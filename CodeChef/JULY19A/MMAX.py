#source geeksforgeeks.org
def mod(num, a): 
      
    # Initialize result 
    res = 0
  
    # One by one process all digits 
    # of 'num' 
    for i in range(0, len(num)): 
        res = (res * 10 + int(num[i])) % a; 
  
    return res
#end of source

t=int(input())
for xxx in range(t):
    n=int(input())
    k=input()
    x=mod(k,n)
    if n%2==1:
        print((min(x,n-x))*2)
    else:
        if n//2 == x:
            print((x*2)-1)
        else:
            print((min(x,n-x))*2)
    
