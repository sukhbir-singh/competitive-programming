#include <stdio.h>

int main()
{
	typedef long long lg;
	lg times,i,j,j1,k,n;
	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld",&n);
		lg arr1[n],arr2[n],diff[n],smd123[n],sum=0;

		for(j=0;j<n;j++)
		scanf("%lld",&arr1[j]);

		for(j=0;j<n;j++)
		scanf("%lld",&arr2[j]);

		lg maxcount=0,count=n,start,tempcount;

		smd123[0]=arr1[j]-arr2[j];

		for(j=0;j<n;j++){
			diff[j]=arr1[j]-arr2[j];
		}

		printf("\ndiff array : ");

		for(j=0;j<n;j++){
			printf("%lld ",diff[j]);
		}
		printf("\n");

			count=n;
			lg ans=-1;

	while(count>=1){

		for(start=0;start+count-1<n;start++){
			tempcount=0;
			sum=0;
			for(j=start;tempcount<count;j++,tempcount++,j++){
				sum+=diff[j];
				printf("adding %lld ", diff[j]);
			}
				printf("\nsum %lld\n",sum );
			if(sum>=0){
				ans=count;
				break;
			}
		}	
			if(ans!=-1){
				break;
			}

		count--;
	}

		
		printf("%lld\n",count );

	}

}
