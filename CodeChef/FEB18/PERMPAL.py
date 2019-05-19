t=int(input())
for rrr in range(t):
    s=input()
    d={'a':[0],
        'b':[0],
        'c':[0],
        'd':[0],
        'e':[0],
        'f':[0],
        'g':[0],
        'h':[0],
        'i':[0],
        'j':[0],
        'k':[0],
        'l':[0],
        'm':[0],
        'n':[0],
        'o':[0],
        'p':[0],
        'q':[0],
        'r':[0],
        's':[0],
        't':[0],
        'u':[0],
        'v':[0],
        'w':[0],
        'x':[0],
        'y':[0],
        'z':[0]}
        '''the values are assigned to the alphabets is a int list with initial element zero which will be increased 
            to represent the no of time a charater repeat, also the following elements of the list will be the index of
            the characters'''
    s1=list(s)
    for index,x in enumerate(s1):
        d[x].insert(0,index+1)
        d[x][-1]+=1
    ch=''
    ind=0
    count=0
    for x in ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']:
        if d[x][-1]%2==1:
            ch=x
            ind=d[x][(d[x][-1]-1)]
            d[x][-1]-=1
            count+=1
    if count>1:
        print("-1")
        continue
    elif count in [0,1]:
        for x in ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']:
            for ee2e in range(d[x][-1]//2):
                print(d[x][(d[x][-1]-1)],end=' ')
                d[x][-1]-=1
        if count==1:
            print(ind,end=" ")
        for x in ['z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a']:
            for ee2e in range(d[x][-1]):
                print(d[x][(d[x][-1]-1)],end=' ')
                d[x][-1]-=1   
    print() 
