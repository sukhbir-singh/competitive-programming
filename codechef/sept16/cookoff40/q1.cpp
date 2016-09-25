#include <bits/stdc++.h>
using namespace std;

int main()
{
	typedef long long lg;
	lg times,i,j,a,b,c,d;
	scanf("%lld",&times);
	
	for(i=0;i<times;i++)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);

		lg count=0;

		for(j=a;j<=b;j++){
			if(j>=d){
				break;
			}

			if(j>=c){
				lg temp=d-j;
				count+=temp;
			}else{
				count+=d-c+1;
			}
		}
	
		printf("%lld\n",count);
	
	}

return 0;
}
