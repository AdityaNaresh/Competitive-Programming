#include<bits/stdc++.h>
using namespace std;
  
int max(int a, int b)
{
    return (a > b)? a : b;
}
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,count=0,c1=0,d1=0;
        char a[1000000],b[1000000],c[1000000],d[1000000];
        cin>>n>>m;
        cin>>a;
        cin>>b;
        for (int i=0;i<=n-2;i++)
        {
            if (a[i]==a[i+1]){
                count+=1;
            }
            else
            {
                c[c1]=a[i];
                c1++;
            }
        }
        c[c1]=a[n-1];
        c1++;
        for (int i=0;i<=m-2;i++)
        {
            if (b[i]==b[i+1]){
                count+=1;
            }
            else{
                d[d1]=b[i];
                d1++;
            }
        }
        d[d1]=b[m-1];
        d1++;
        count=count+lcs(c,d,c1,d1);
        cout<<(n+m-count)<<endl;
        
    }
 
  return 0;
} 
