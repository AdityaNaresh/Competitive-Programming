/*
	author : Aditya Naresh
  	handle : king_in_n0rth
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<ll> vll;

typedef vector< vll > vvll;

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define len(a) int((a).size())
#define all(c) (c).begin(),(c).end()

#define loop(i, a, b)	for (ll i(a); i < (b); i ++)
#define test() int t; cin>>t; while(t--)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
ll n, l;
vector<vector<ll>> adj;

ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;
vll path;

void addEdge(ll u, ll v)
{
    adj[u].pb(v);
    adj[v].pb(u);
}

void dfs(ll v, ll p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(ll u, ll v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void find_path(ll child, ll parent) {
  if (child == parent) {
    path.pb(child);
    return;
  }
  path.pb(child);
  for (ll u : adj[child]) {
      if (is_ancestor(u,child)) {
        find_path(u,parent);
      }
  }
  
}

ll sumit(ll u, ll ig1, ll ig2) {
  vll sum;
  ll ans=0;
  for (ll x:adj[u]){
    if (x!=ig1 && x!=ig2) {
      if (is_ancestor(x,u)) {
        sum.pb(n-ceil((tout[u]-tin[u])/2.0));
      }
      else {
        sum.pb(ceil((tout[x]-tin[x])/2.0));
      }
    }
  }
  ll ns=sum.size();
  loop (i,0,ns-1) {
    loop (j,i+1,ns){
      ans+=sum[i]*sum[j];
    }
    ans+=sum[i];
  }
  if(ns>0)
  ans+=sum[ns-1];
  return ans+1;
}

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<ll>(l + 1));
    dfs(root, root);
}


int main() {

	FAST_IO;
	test(){
		ll n1,q;
		cin>>n1>>q;
		n = n1;
    adj.assign(n,vll());
    if(n==1) {
        adj[0].pb(0);
    }
		loop(i,0,n-1){
			ll u,v;
			cin>>u>>v;
			addEdge(u-1, v-1);
		}
    
    preprocess(0);
		loop(xxx,0,q){
			ll a,b;
      ll sum = 0;
			cin>>a>>b;
      if(a==b) {
        cout<<sumit(a-1,-1,-1)<<endl;
        continue;
      }
      ll lca1 = lca(a-1,b-1);
      find_path(a-1,lca1);
      path.erase(path.end()-1);
      vll pathi = path;
      path.clear();
      find_path(b-1,lca1);
      for (ll i=path.size()-1;i>=0;i--){
          pathi.pb(path[i]);
      }
      ll pathsize = pathi.size();
      loop(i, 0, pathsize) {
        if (i==0){
          sum+=sumit(pathi[i],pathi[i+1],pathi[i+1]);
          
        }
        else if(i==pathsize-1){
          sum+=sumit(pathi[i],pathi[i-1],pathi[i-1]);
        }
        else{
          sum+=sumit(pathi[i],pathi[i+1],pathi[i-1]);
        }
      }
      cout<<sum<<endl;
      path.clear();
		}
    adj.clear();
    tin.clear();
    tout.clear();
    up.clear();
    n=0;
    l=0;
    
	}

	return 0;
}
