//for this problem i made an algo and applied using python but it got TLE and after a few try it got passed when i used C++
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
	long long t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    long long a[n],b[n];
	    for (long long i=0;i<n;i++){cin>>a[i];b[i]=2;}
	    b[0]=1;
	    b[n-1]=1;
	    if (n==1) cout<<"0\n";
	    else if (n==2) cout<<"1 1\n";
	    else
	    {
	    for (long long i=0;i<n-1;i++)
	    {
	        long long sum=0;
	        for (long long j=i+1;j<n-1;j++)
	        {
	            sum+=a[j];
	            if (sum<=a[i])
	            {
	                b[j+1]++;
	            }
	            else
	            {
	                break;
	            }
	        }
	    }
	    for (long long i=n-1;i>0;i--)
	    {
	        long long sum=0;
	        for (long long j=i-1;j>0;j--)
	        {
	            sum+=a[j];
	            if (sum<=a[i])
	            {
	                b[j-1]++;
	            }
	            else
	            {
	                break;
	            }
	        }
	    }
	    for (long long i=0;i<n;i++)cout<<b[i]<<" ";
	    cout<<endl;
	}}
	return 0;
} 
