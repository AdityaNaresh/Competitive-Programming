n,m=[int(c) for c in input().split()]
s=[int(c) for c in input().split()]
w=[int(c) for c in input().split()]
adj=[[]]*n
char='C'
ans=['o']*n
def DFSUtil(v,visited):
    visited[v]= True
    ans[v]=char
    if char=='C':
        char='G'
    else:
        char = 'C'

    for i in adj[v]: 
        if visited[i] == False: 
            DFSUtil(i, visited) 
def DFS(v): 
    visited = [False]*(len(adj)) 
 
    DFSUtil(v,visited)
for xxx in range(m):
    u,v=[int(c) for c in input().split()]
    adj[u-1].append(v-1)
    adj[v-1].append(u-1)

print("-1")
for xx in ans:
    if xx=='o':
        print(char,end="")
        if char=='C':
            char='G'
        else:
            char = 'C'
    else:
        print(xx,end='')
print()
