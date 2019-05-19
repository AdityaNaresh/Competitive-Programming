#include<bits/stdc++.h>
using namespace std;
long long int start=0,end1=0;
 
long long int maxSubArraySum(long long int a[], long long int size)
{
    long long int max_so_far = a[0]-1, max_ending_here = 0;
    
    start =0;
    end1 = 0;
    long long int s=0;
 
    for (long long int i=0; i< size; i++ )
    {
        max_ending_here += a[i];
 
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end1 = i;
        }
 
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i+1;
        }
    }
    return max_so_far;
}
int main()
{
     ios_base::sync_with_stdio(false);
    long long int t;
    cin>>t;
    while(t--){
        long long int n,k,sum=0;
        cin>>n>>k;
        long long int a[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if (k==1){
            long long int max_sum = maxSubArraySum(a, n);
            cout<<max_sum<<endl;
        }
        else if (k==2){
            long long int a1[2*n];
            for(long long int i=0;i<n;i++)a1[i]=a[i];
            for(long long int i=0;i<n;i++)a1[i+n]=a[i];
            long long int max_sum = maxSubArraySum(a1, 2*n);
            cout<<max_sum<<endl;
        }
        else
        {
            if (sum<=0)
            {
                long long int a1[2*n];
                for(long long int i=0;i<n;i++)a1[i]=a[i];
                for(long long int i=0;i<n;i++)a1[i+n]=a[i];
                long long int max_sum = maxSubArraySum(a1, 2*n);
                cout<<max_sum<<endl;
            }
            else
            {
                long long int a1[3*n];
                for(long long int i=0;i<n;i++)a1[i]=a[i];
                for(long long int i=0;i<n;i++)a1[i+n]=a[i];
                for(long long int i=0;i<n;i++)a1[i+2*n]=a[i];
                long long int max_sum = maxSubArraySum(a1, 3*n);
                if (k==3)
                {
                    cout<<max_sum<<endl;
                }
                else if (start<=n&&end1>=(2*n-1))
                {
                    max_sum+=((sum)*(k-3));
                    cout<<max_sum<<endl;
                }
                else{
                    cout<<max_sum<<endl;
                }
            }
        }
    }
    return 0;
}
