#include <iostream>
using namespace std;
 
int main() {
	long int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    if (n==1)
	    {
	        cout<<"1"<<endl;
	    }
	    else
	    {
	        long long sum=0,counter=0,ap=1;
	        while(true)
	        {
	            sum+=ap;
	            ap++;
	            counter++;
	            if (sum>n)
	            {
	                break;
	            }
	            else if((sum+ap-n+1)>=(n-sum))
	            {
	                sum=n*2-sum;
	                break;
	            }
	        }
	        cout<<(counter+(sum-n))<<endl;
	    }
	}
	return 0;
} 
