#include <stdio.h>

int main()
{
	typedef long long lg;
	lg times,i,j,k,n;
	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld",&n);
		lg arr1[n],arr2[n],diff[n],sum=0;

		for(j=0;j<n;j++)
		scanf("%lld",&arr1[j]);

		for(j=0;j<n;j++)
		scanf("%lld",&arr2[j]);

		lg maxcount=0,count=0;

		for(j=0;j<n;j++){
			diff[j]=arr1[j]-arr2[j];
		}

		for(j=0;j<n;j++){
			sum=sum+diff[j];

			if(sum>=0){
				count++;
			}else{
				if(diff[j]>=0){
					count=1;
					sum=diff[j];
				}else{
					count=0;
					sum=0;
				}

			}

			if(count>maxcount){
				maxcount=count;
			}

		}

		printf("%lld\n",maxcount );

	}

}
