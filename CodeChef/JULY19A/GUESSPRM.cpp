/*
_____ ______                                    _________                      _________
__  /____  /_ _____         _______ ___ ______ _______  /        _____________ ______  /_____ ________
_  __/__  __ \_  _ \        __  __ `__ \_  __ `/_  __  /         _  ___/_  __ \_  __  / _  _ \__  ___/
/ /_  _  / / //  __/        _  / / / / // /_/ / / /_/ /          / /__  / /_/ // /_/ /  /  __/_  /
\__/  /_/ /_/ \___/ ________/_/ /_/ /_/ \__,_/  \__,_/   ________\___/  \____/ \__,_/   \___/ /_/
                    _/_____/                             _/_____/
  	handle : the_mad_coder
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector< int > vi;
typedef vector<ll> vll;
typedef vector <string> vs;
typedef pair< int,int > pii;
typedef pair< ll,ll > pll;

typedef vector < pii > vpii;
typedef vector < pll > vpll;

typedef vector< vi > vvi;
typedef vector< vll > vvll;

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define len(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define vpresent(c,x) (find(all(c),x) != (c).end())
#define vsum(c) accumulate(all(c), 0);

#define srt(v)	sort (all (v))
#define fill (x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)

#define fir first
#define sec second

#define trans(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define loop(i, a, b)	for (ll i(a); i < (b); i ++)
#define test() int t; scanf("%d",&t); while(t--)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define PI 3.14159265358979323
#define MIN -1e9
#define MAX  1e9
const ll MOD = 1000000007LL;

#define trace1(x1)					cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)				cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)			cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}

vll factorize(long long n) 
{ 
    int count = 0; 
    vll v;
    while (!(n % 2)) { 
        n >>= 1;
        count++; 
    }
    if (count) 
        v.pb(2); 
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
             v.pb(i);
    }
    if (n > 2) {
        v.pb(n);
        }
    return v;
} 

int main() {

	//FAST_IO;
	test(){
	    ll num = 31627;
		cout<<1<<" "<<num<<endl;
		ll r;
		cin>>r;
		if (r==0){
		    cout<<2<<" "<<num<<endl;
		    string s;
		    cin>>s;
		    continue;
		}
		ll m = pow(num,2);
		ll n = m-r;
		vll v=factorize(n);
		
		if (len(v)==1){
		    cout<<2<<" "<<v[0]<<endl;
		    string s;
		    cin>>s;
		    continue;
		}
		sort(all(v), greater<ll>());
		
		//for (auto i1 = v.begin(); i1 != v.end(); ++i1) 
        //cout << *i1 << " ";
        
        
		num = sqrt(v[1])+1;
		//num = sqrt(v[0])-1;
		cout<<1<<" "<<num<<endl;
		cin>>r;
		m = pow(num,2);
		n=m-r;
		if (r==m){
		    cout<<2<<" "<<v[0]<<endl;
		    string s;
		    cin>>s;
		    continue;
		}
		vll v2=factorize(n);
		
		sort(all(v2), greater<ll>());
		
		//for (auto i1 = v2.begin(); i1 != v2.end(); ++i1) 
        //cout << *i1 << " ";
		ll i=0;
		while(1){
		    //cout<<v2[i]<<endl;
		    if(vpresent(v,v2[i])){
		        i=v2[i];
		        break;
		    }
		    i++;
		}
		cout<<2<<" "<<i<<endl;
		string s;
		cin>>s;
		
	}

	return 0;
}
