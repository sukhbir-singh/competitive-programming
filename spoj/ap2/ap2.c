#include <stdio.h>

int main()
{
	typedef long long lg;
	lg times,i,j,k,x,y,z,n,diff;
	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld%lld%lld",&x,&y,&z);

		n=2*z/(x+y);
		diff=(y*y-x*x)/(2*z-5*x-5*y);

		printf("%lld\n",n);
		lg temp=x-2*diff;

		for(j=0;j<n;j++){
			printf("%lld ",temp);
			temp=temp+diff;
		}
		printf("\n");
	}

}
