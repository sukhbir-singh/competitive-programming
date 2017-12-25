#include <bits/stdc++.h>
using namespace std;

int main()
{
	typedef long long lg;
	lg r,i,j,k,a,b,c,d;
	scanf("%lld",&r);

	lg count=0;
	long long arr[1000][1000];

	int flag1=0;
	
	for(i=1;i<=100*r;i++){
		for(j=i;j<=100*r;j++){
			for(k=j;k<=100*r;k++){

				if((i+j+k)%2!=0){
					continue;
				}

				if(i+j<k || j+k<i || k+i<j){
					continue;
				}

				lg s=(i+j+k)/2;

				lg area=s*(s-i)*(s-j)*(s-k);

				if(area==s*s*r*r){
					arr[count][0]=i;
					arr[count][1]=j;
					arr[count][2]=k;

					count++;
				}
			}
		}
	}

	printf("%lld\n",count );
	for(i=0;i<count;i++){
		printf("%lld %lld %lld\n",arr[i][0],arr[i][1],arr[i][2] );
	}
	
return 0;
}
