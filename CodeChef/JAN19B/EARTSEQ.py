maximum= 10000000
ispritable = [True] * maximum  
pri = []  
table = [None] * (maximum)  
def manipulated_seive(N):  
    ispritable[0] = ispritable[1] = False
    for i in range(2, N):  
        if ispritable[i] == True:  
            pri.append(i)  
            table[i] = i  
        j = 0
        while (j < len(pri) and
               i * pri[j] < N and
                   pri[j] <= table[i]): 
            ispritable[i * pri[j]] = False
            table[i * pri[j]] = pri[j] 
            j += 1
import math
N = int(611954)
manipulated_seive(N)
l=len(pri)
t=int(input())
for xxx in range(t):
    test=[]
    n=int(input())
    if n<=3401:
        for x in range(n-1):
            print(pri[x]*pri[x+1],end=" ")
        print(pri[0]*pri[n-1])
    else:
        counter=257
        for x in range(256):
            print(pri[x]*pri[x+1],end=" ")
            test.append(pri[x]*pri[x+1])
        print(pri[0]*pri[256],end=" ")
        test.append(pri[0]*pri[256])
        temp=0
        it=0
        for x in range(257,49700,257):
            i=0
            for c in range(x,x+256):
                print(pri[i]*pri[c],end=" ")
                test.append(pri[i]*pri[c])
                counter+=1
                if counter==n-2:
                    print(pri[257]*pri[c],end=" ")
                    print(pri[49999]*pri[257],end=" ")
                    test.append(pri[257]*pri[49999])
                    it=1
                    temp=pri[49999]
                    break
                print(pri[i+1]*pri[c],end=" ")
                test.append(pri[i+1]*pri[c])
                counter+=1
                if counter==n-2:
                    print(pri[i+1]*pri[250],end=" ")
                    print(pri[49999]*pri[250],end=" ")
                    test.append(pri[250]*pri[49999])
                    counter+=1
                    it=1
                    temp=pri[49999]
                    break
                i+=1
            if it==1:
                break
            print(pri[x+256]*pri[i],end=" ")
            test.append(pri[x+256]*pri[i])
            counter+=1
            if counter==n-2:
                print(pri[x+256]*pri[257],end=" ")
                test.append(pri[x+256]*pri[256])
                print(pri[49999]*pri[257],end=" ")
                test.append(pri[257]*pri[49999])
                temp=pri[49999]
                break
            else:
                print(pri[x+256]*pri[0],end=" ")
                test.append(pri[x+256]*pri[0])
                counter+=1
        print(pri[0]*temp)
        test.append(pri[0]*temp)
        
