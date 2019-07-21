#include <bits/stdc++.h>
using namespace std;

typedef long int ll;
typedef vector<int> vll;


#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


ll prefix[401]={};
int n;
ll dp[401][401]={};
void fillPrefixSum(vll &arr, int n) 
{ 
    prefix[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        prefix[i] = prefix[i-1] + arr[i]; 
} 
ll find(int i,int j){
    if (i<=j){
        //cout<<i<<" "<<j<<endl;
        //cout<<prefix[j]-prefix[i-1]<<endl;
        return prefix[j]-prefix[i-1];
    }
    else {
        //cout<<prefix[j]+(prefix[n-1]-prefix[i-1])<<endl;
        return prefix[j]+(prefix[n-1]-prefix[i-1]);
    }
}
int main() {

	FAST_IO;
	int t;
	cin>>t;
	while(t--){
	    n=0;
	    cin>>n;
	    vll v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    fillPrefixSum(v,n);
	    dp[n-1][0]=v[0]+v[n-1];
	    for(int i=0;i<n-1;i++){
	        dp[i][i+1]=v[i]+v[i+1];
	    }
	    for(int l=2;l<n;l++){
	        for(int i=0;i<n;i++){
	            int j =(i+l)%n;
	            int y = (i+1)%n;
	            ll min = v[i] + (dp[y][j])+find(y,j);
	            int x=y;
                while (x!=j){
                    y = (x+1)%n;
                    ll temp = (dp[i][x]+dp[y][j])+find(i,x)+find(y,j);
                    if (temp<min){
                        min = temp;
                    }
                    x=y;
                }
                dp[i][j] = min;
	        }
	    }
	    ll min = dp[0][n-1];
	    for(int i=1;i<n;i++){
	        ll temp = dp[i][(i+n-1)%n];
	        if (min>temp){
	            min = temp;
	        }
	    }
	    cout<<min<<endl;
	    
	}
	return 0;
}
