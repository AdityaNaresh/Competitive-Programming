#include<bits/stdc++.h>
 
int main()
 
{
 
int T;
 
unsigned long int N,x,sum,i,j,obj,a[2],diff,h;
 
scanf("%d",&T);
while(T>0)
 
{
 
T--;
 
a[0]=0;
 
a[1]=0;
 
scanf("%lu %lu",&x,&N);
 
h=N/2;
 
sum=((N*(N+1))/2)-x;
 
if(sum%2!=0||N<=2||(N==3&&x==2))
 
printf("impossible\n");
 
 
else
 
{
 
	 if(h>=x)
 
	 obj=((h*(h+1))/2)-x;
 
	 else obj=(h*(h+1))/2;
 
	 for(i=h+1;i<=N;i++)
 
	 {
 
	 if(sum/2>obj)
 
	 {
 
		if(i==x)
 
		continue;
 
		else
 
		obj=obj+i;
 
	 }
 
	 else
 
	 break;
 
	 }
 
	 i--;
 
	 diff=obj-sum/2;
 
	 if(x==1&&diff==1)
 
	 {
 
	 printf("20");
 
	 for(j=3;j<i;j++)
 
	 printf("1");
 
	 printf("01");
 
	 for(j=i+2;j<=N;j++)
 
	 printf("0");
 
	 printf("\n");
 
	 continue;
 
	 }
 
 
	 if(x==2&&diff==2)
 
	 {
 
	 printf("021");
 
	 for(j=4;j<i;j++)
 
	 printf("0");
 
	 printf("10");
 
	 for(j=i+2;j<=N;j++)
 
	 printf("1");
 
	 printf("\n");
 
	 continue;
 
	 }
 
 
	 if((diff!=0)&&(x!=1||diff!=1)&&(x!=2||diff!=2))
 
	 {
 
	 if(diff<=i&&diff!=x)
 
	 a[0]=diff;
 
 
	 else
 
	 {
 
		 a[0]=1;
 
		 a[1]=diff-1;
 
	 }
 
	 }
 
 
	 if(a[0]==1)
 
	 {
 
	 printf("0");
 
	 for(j=2;j<=i;j++)
 
	 {
 
		 if(j==x)
 
		 printf("2");
 
		 else if(j==a[1])
 
		 printf("0");
 
		 else
 
		 printf("1");
 
	 }
 
	 for(j=i+1;j<=N;j++)
 
	 {
 
		 if(j==x)
 
		 {
 
		 printf("2");
 
		 continue;
 
		 }
 
		 printf("0");
 
	 }
 
	 printf("\n");
 
	 }
 
 
	 else
 
	 {
 
	 for(j=1;j<=N;j++)
 
	 {
 
		 if(j==x)
 
		 {
 
		 printf("2");
 
		 continue;
 
		 }
 
		 else if(j==a[0]||j>i)
 
		 printf("1");
 
 
		 else if(j<=i)
 
		 printf("0");
 
	 }
 
	 printf("\n");
 
	 }
 
 
}
 
}
 
return 0;
 
} 
