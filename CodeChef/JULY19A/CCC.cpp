#include <bits/stdc++.h>
using namespace std;

typedef long  ll;
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
ll ans[1001]={-1};

#define loop(i, a, b)	for (int i(a); i < (b); i ++)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

ll find(int a[],int n){
    ll sum[n];
	loop(i,0,n){
	   sum[i]=(a[i]*(n-i));
	}
	ll min = sum[0];
	int gg=0;
	loop(i,1,n){
	    if (sum[i]<=min){
            min=sum[i];
	        gg=i;
         }
	}
	//cout<<"i"<<gg<<endl;
	return min;
}
ll fun(int a[],int n,int z);
ll funmid(int a[],int n,int z){
    if (ans[n]==-1){
        ll temp = fun(a,n,z);
        ans[n]=temp;
        return temp;
    }
    return ans[n];
    
}
ll fun(int a[],int n,int z){
    /*loop(i,0,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    ll sum=0;
    int index;
    if (z==1){
        return find(a,n);
    }
    //cout<<"i"<<index<<endl;
        index=z-1;
        ll sum1[n-index]={};
        loop(j,index,n){
        loop(i,j-z+1,j+1){
            sum1[j-index]+=a[i];
        }
        sum1[j-index]+=(a[j]*(n-j-1));
        }
        sum=sum1[0];
        loop(i,0,n-index){
            if (sum1[i]<sum)sum = sum1[i];
        }
        index = 0;
        ll sum2[z-1]={};
        loop(j,index,z-1){
        int n1 = n-j-1;
        int a1[n1];
        int z1 = z-j-1;
        loop(i,0,j+1){
            sum2[j]+=a[i];
        }
        sum2[j]+=(a[j]*(n-j-1));
        loop(i,0,n1){
            a1[i]=a[i+j+1]-a[j];
        }
        //cout<<sum<<endl;
        sum2[j]+=funmid(a1,n1,z1);
        }
        loop(i,0,z-1){
            if (sum2[i]<sum)sum = sum2[i];
        }
    
    
    return sum;
}

int main() {

	FAST_IO;
	int t;
	cin>>t;
	while(t--){
	    int n,z;
	    cin>>n>>z;
	    int a[n];
	    loop(i,0,n){
	        cin>>a[i];
	        ans[i]=-1;
	    }
	    ans[n]=-1;
	    if (n==z){
	        ll sum = 0;
	        loop(i,0,n){
	            sum+=a[i];
	        }
	        cout<<sum<<endl;
	        continue;
	    }
	    sort(a,a+n);
	    ll min = fun(a,n,z);
	    cout<<min<<endl;
	}
	return 0;
}
