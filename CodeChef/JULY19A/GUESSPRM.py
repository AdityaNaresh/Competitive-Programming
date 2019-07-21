import math
#factorize is geeks for geeks implimentation of the same
def factorize(n):
    count = 0;
    a=[]
    while ((n % 2 > 0) == False):
        n= n>>1
        count += 1
    if (count > 0):
        a.append(2)
    i=3
    while i<=int(math.sqrt(n)):
        count = 0
        while (n % i == 0):
            count += 1
            n = n // i
        if (count > 0):
            a.append(i)
        i += 2
    if (n > 2):
        a.append(n)
    return a

t=int(input())
for xx in range(t):
    num = 31627
    print("1 31627",flush = True)
    m=int(input())
    if m==0:
        print("2 31627",flush = True)
        flush = input()
        continue
    n = int(math.pow(num,2)) - m
    a1 = factorize(n)
    
    if len(a1)>=2:
        sorted(a1)
        num = int(math.sqrt(a1[-2]))+1
        print("%d %d"%(1,num),flush = True)
        m=int(input())
        n =int(math.pow(num,2)) - m
        if n==0:
                print("2 %d"%(a1[-1]),flush = True)
                flush=input()
                continue
        a2 = factorize(n)
        #print(a1)
        #print(a2)
        if len(a2)==1:
            print("2 %d"%(a2[0]),flush = True)
            flush=input()
        else:
            for x in a1[::-1]:
                if x in a2:
                    print("2 %d"%(x),flush = True)
                    flush=input()
                    break
    else:
        print("%d %d"%(2,a1[0]),flush = True)
        flush=input()
