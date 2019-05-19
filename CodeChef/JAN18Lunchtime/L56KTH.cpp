// Brute Force attack only for 1st subtask
#include <bits/stdc++.h>
using namespace std;
 
main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    int z[1000000],kk;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        z[i]=a[i]*a[i];
        kk++;
    }
    
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            int xor1=a[i];
            for (int h=i+1;h<=j;h++){
                xor1^=a[h];
                }
                int small = a[i];
    int gg;
 
    for(gg=i;gg<=j;gg++)
    {
        if(a[gg]<small)
        {
            small = a[gg];
        }
    }
            z[kk++]=xor1*small;
            }}
        sort(z,z+kk);
        cout<<z[k-1];
        return 0;} 
