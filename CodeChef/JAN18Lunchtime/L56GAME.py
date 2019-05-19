import math
t=int(input())
for rrr in range(t):
    n=int(input())
    numbers=[int(e) for e in input().split()]
    count_odd = 0
    count_even = 0
    sum=0
    for x in numbers:
        if not x % 2:
    	     count_even+=1
        else:
	         count_odd+=1
    if count_even>0:
	    if count_odd%2==1:
	        print("2")
	    else:
	        print("1")
    else:
	    if count_odd==1:
	        print("1")
	    elif count_odd%2==0:
	        print("1")
	    else:
	        print("2") 
