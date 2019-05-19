#include <bits/stdc++.h>
using namespace std;
void change(long long n,long long m)
{
    long long a[n][m];
    for (long i=0;i<n;i++)
	    {
	        for(long j=0;j<m;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
    if (a[0][0]==-1)
    {
        if (a[1][0]==-1||a[0][1]==-1)
        {
            a[0][0]=max(a[1][0],a[0][1]);
            a[0][0]=max(a[0][0],(long long)1);
        }
        else
        a[0][0]=min(a[1][0],a[0][1]);
    }
    
    for (long i=0;i<n;i++)
	    {
	        for(long j=0;j<m;j++)
	        {
	            if (a[i][j]==-1)
	            {
	                if(i==n-1&&j==m-1)
    {
        a[n-1][m-1]=max(a[n-2][m-1],a[n-1][m-2]);
    }
    else if (i==0&&j==m-1)
    {
        a[0][m-1]=a[0][m-2];
        if (a[0][m-2]>a[1][m-1]&&!(a[1][m-1]==-1))
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    else if(i==n-1&&j==0)
    {
        a[n-1][0]=a[n-2][0];
        if (a[n-2][0]>a[n-1][1]&&!(a[n-1][1]==-1))
        {
            cout<<"-1"<<endl;
            return;
        }
    }
	                else if (i==0)
	                {
	                    if ((a[0][j-1]<=a[0][j+1]|| a[0][j+1]==-1)&&(a[0][j-1]<=a[1][j]||a[1][j]==-1))
	                    {
	                        a[0][j]=a[0][j-1];
	                        //cout<<a[i][j]<<endl;
	                    }
	                    else
	                    {
	                        cout<<"-1"<<endl;
                            return;
	                    }
	                }
	                else if (j==0)
	                {
	                    if ((a[i-1][0]<=a[i+1][0]|| a[i+1][0]==-1)&&(a[i-1][0]<=a[i][1]||a[i][1]==-1))
	                    {
	                        a[i][0]=a[i-1][0];
	                        //cout<<a[i][j]<<endl;
	                    }
	                    else
	                    {
	                        cout<<"-1"<<endl;
                            return;
	                    }
	                }
	                else if (j==m-1)
	                {
	                    if ((a[i-1][m-1]<=a[i+1][m-1]|| a[i+1][m-1]==-1)&&(a[i+1][m-1]>=a[i][m-2]||a[i+1][m-1]==-1))
	                    {
	                        a[i][j]=max(a[i+1][m-1],a[i][j-1]);
	                        //cout<<a[i][j]<<endl;
	                    }
	                    else
	                    {
	                        cout<<"-1"<<endl;
                            return;
	                    }
	                }
	                else if (i==n-1)
	                {
	                    if ((a[n-1][j-1]<=a[n-1][j+1]|| a[n-1][j+1]==-1)&&(a[n-1][j+1]>=a[n-2][j]||a[i][j+1]==-1))
	                    {
	                        a[i][j]=max(a[i][j+1],a[i-1][j]);
	                        //cout<<a[i][j]<<endl;
	                    }
	                    else
	                    {
	                        cout<<"-1"<<endl;
                            return;
	                    }
	                }
	                else
	                {
	                    if ((a[i-1][j]<=a[i+1][j]|| a[i+1][j]==-1)&&(a[i][j-1]<=a[i][j+1]|| a[i][j+1]==-1)&&(max(a[i][j-1],a[i-1][j])<=a[i+1][j]||a[i+1][j]==-1)&&(max(a[i][j-1],a[i-1][j])<=a[i][j+1]||a[i][j+1]==-1))
	                    {
	                        a[i][j]=max(a[i][j-1],a[i-1][j]);
	                        //cout<<a[i][j]<<endl;
	                    }
	                    else
	                    {
	                        cout<<"-1"<<endl;
                            return;
	                    }
	                }
	            }
	        }
	    }
	    for (long i=0;i<n;i++)
	    {
	        for(long j=0;j<m-1;j++)
	        {
	            if (a[i][j]>a[i][j+1])
	            {
	                cout<<"-1"<<endl;
	                return;
	            }
	        }
	    }
	    for (long j=0;j<m;j++)
	    {
	        for(long i=0;i<n-1;i++)
	        {
	            if (a[i][j]>a[i+1][j])
	            {
	                cout<<"-1"<<endl;
	                return;
	            }
	        }
	    }
	    for (long i=0;i<n;i++)
	    {
	        for(long j=0;j<m;j++)
	        {
	            cout<<a[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	    return;
}
int main() {
	long int t;
	cin>>t;
	while(t--)
	{
	    long long n,m;
	    cin>>n>>m;
	    change(n,m);
	}
	return 0;
}
