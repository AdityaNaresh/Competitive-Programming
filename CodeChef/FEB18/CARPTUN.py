t=int(input())
for rrr in range(t):
    n=input()
    num=[int(e) for e in input().split()]
    c,d,s=[int(e) for e in input().split()]
    print(float(max(num)*(c-1)))

''' 
    Solution of this problem is indeed hilarious its based on the concept, i.e. "The rate determining step" of
    chemical kinetics
'''
