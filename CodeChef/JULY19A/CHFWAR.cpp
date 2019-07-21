#include <bits/stdc++.h>
using namespace std;

typedef long int ll;
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


#define loop(i, a, b)	for (int i(a); i < (b); i ++)

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

ll findD(int a[],int n,int p){
    int f1=0,l1=p-1,f2=p,l2=n-1,len1=int(l1-f1+1),len2=int(l2-f2+1),x=1;
    ll d=0;
    while(!(len2==1&&len1==0)){
        if(len1==0&&len2>2){
            if(len2%2){
                d+=a[l2];
                len2=int((len2+1)/2);
            }
            else{
                l2=l2-x;
                len2=int(len2/2);
            }
        }
        else{
            if(len1%2){
                d+=a[l1];
                len1=int((len1+1)/2);
            }
            else{
                l1=l1-x;
                len1=int(len1/2);
            }
            if(len2%2){
                len2=int((len2+1)/2);
                f1=f1+(x*2);
                len1=len1-1;
            }
            else{
                l2-=x;
                len2=int(len2/2);
            }
        }
        x*=2;
    }
    return d;
}
int main() {

	//FAST_IO;
	int t;
	cin>>t;
	while(t--){
	    ll d = 0;
	    int n;
	    cin>>n;
	    int a[n];
	    
	    loop(i,0,n-1){
	        cin>>a[i];
	    }
	    int p=3;
	    int f;
	    cin>>f;
	    bool flag = true;
	    loop(i,0,n-1){
	        if (a[i]<=f){
	            flag = false;
	            break;
	        }
	    }
	    if (flag){
	        cout<<"impossible"<<endl;
	        continue;
	    }
	    ll min = -1;
	    loop(i,0,n-1){
	        if(a[i]<=f){
	            if (min==-1){
	                min=findD(a,n-1,i);
	                p=i;
	            }
	            else{
	                d=findD(a,n-1,i);
	                if (d<min){
	                    min=d;
	                    p=i;
	                }
	            }
	            
	        }
	    }
	    
	    min+=f;
	    cout<<"possible"<<endl;
	    cout<<p+1<<" "<<min<<endl;
	    
	}
	return 0;
}
