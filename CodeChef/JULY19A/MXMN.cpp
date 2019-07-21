// FOR subtask 1 only
// MST CODE taken from:https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
#include <bits/stdc++.h>
using namespace std;



typedef long int ll;
typedef vector<int> vll;
#define len(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define vsum(c) accumulate(all(c), 0);
#define pb push_back
#define srt(v)	sort (all (v))
#define fill (x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)


#define loop(i, a, b)	for (int i(a); i < (b); i ++)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

ll ans[2001][2001];
ll mstw[2001][2001];
int current = 0;

class Graphi 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
  
    // A recursive function used by DFS 
    void DFSUtil(int v, bool visited[],ll max); 
public: 
    Graphi(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // DFS traversal of the vertices 
    // reachable from v 
    void DFS(int v); 
}; 
  
Graphi::Graphi(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graphi::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graphi::DFSUtil(int v, bool visited[],ll max) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    ans[current][v] = max;
    
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited,std::max(max,mstw[v][*i])); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graphi::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited,0); 
}


struct Edge 
{ 
	int src, dest, weight; 
}; 

struct Graph 
{ 
	int V, E; 
	struct Edge* edge; 
}; 

struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 

	graph->edge = new Edge[E]; 

	return graph; 
} 

struct subset 
{ 
	int parent; 
	int rank; 
}; 

int find(struct subset subsets[], int i) 
{  
	if (subsets[i].parent != i) 
		subsets[i].parent = find(subsets, subsets[i].parent); 

	return subsets[i].parent; 
} 

void Union(struct subset subsets[], int x, int y) 
{ 
	int xroot = find(subsets, x); 
	int yroot = find(subsets, y); 

	if (subsets[xroot].rank < subsets[yroot].rank) 
		subsets[xroot].parent = yroot; 
	else if (subsets[xroot].rank > subsets[yroot].rank) 
		subsets[yroot].parent = xroot; 

	else
	{ 
		subsets[yroot].parent = xroot; 
		subsets[xroot].rank++; 
	} 
} 

int myComp(const void* a, const void* b) 
{ 
	struct Edge* a1 = (struct Edge*)a; 
	struct Edge* b1 = (struct Edge*)b; 
	return a1->weight > b1->weight; 
} 

void KruskalMST(struct Graph* graph,Graphi &mst) 
{ 
	int V = graph->V; 
	struct Edge result[V]; // Tnis will store the resultant MST 
	int e = 0; // An index variable, used for result[] 
	int i = 0; // An index variable, used for sorted edges 

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 

	struct subset *subsets = 
		(struct subset*) malloc( V * sizeof(struct subset) ); 

	for (int v = 0; v < V; ++v) 
	{ 
		subsets[v].parent = v; 
		subsets[v].rank = 0; 
	} 

	while (e < V - 1 && i < graph->E) 
	{ 
		struct Edge next_edge = graph->edge[i++]; 

		int x = find(subsets, next_edge.src); 
		int y = find(subsets, next_edge.dest); 

		if (x != y) 
		{ 
			result[e++] = next_edge; 
			Union(subsets, x, y); 
		} 
		
	} 
	for (i = 0; i < e; ++i) {
		mst.addEdge(result[i].src,result[i].dest);
		mst.addEdge(result[i].dest,result[i].src);
		mstw[result[i].src][result[i].dest]=result[i].weight;
		mstw[result[i].dest][result[i].src]=result[i].weight;
	}
	return; 
} 


int main() 
{ 
	
	int n ,m;  
	cin>>n>>m;
	
	struct Graph* graph1 = createGraph(n, m); 
    struct Graph* graph2 = createGraph(n, m); 
    
    loop(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        graph1->edge[i].src = u-1; 
	    graph1->edge[i].dest = v-1; 
	    graph1->edge[i].weight = w;
    }
    
    loop(i,0,m){
        ll u,v,w;
        cin>>u>>v>>w;
        graph2->edge[i].src = u-1; 
	    graph2->edge[i].dest = v-1; 
	    graph2->edge[i].weight = w;
    }
    
    ll a1[n][n];
    Graphi mst1(n);
	KruskalMST(graph1,mst1); 
	loop(i,0,n){
	    current=i;
	    mst1.DFS(i);
	}
	
	loop(i,0,n){
	    loop(j,i+1,n){
	        a1[i][j]=ans[i][j];
	    }
	}
	
    Graphi mst2(n);
	KruskalMST(graph2,mst2); 
	loop(i,0,n){
	    current=i;
	    mst2.DFS(i);
	}
	
	ll mod = 998244353;
	ll sum=0;
	loop(i,0,n){
	    loop(j,i+1,n){
	        sum+=((a1[i][j]*ans[i][j])%mod);
	    }
	}
	cout<<sum%mod<<endl;
	
	return 0; 
} 
