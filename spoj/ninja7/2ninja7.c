#include <stdio.h>
#include <stdlib.h>

int main()
{
	typedef long long lg;
	lg times,i,j,j1,k,n;
	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld",&n);
		
		lg arr1[n],arr2[n];

		for(j=0;j<n;j++)
		scanf("%lld",&arr1[j]);

		for(j1=0;j1<n;j1++)
		scanf("%lld",&arr2[j1]);

		lg subtr[n];

		for(j=0;j<n;j++){
			subtr[j]=arr1[j]-arr2[j];
			//printf("subtr %lld ",subtr[j]);
		}
		//printf("\n");

				lg count=n,sum;
				lg ans=-1,start,tempcount;

			while(count>=1){

				for(start=0;start+count-1<n;start++){
					tempcount=0;
					sum=0;
					for(j=start;tempcount<count;j++,tempcount++){
						sum+=subtr[j];
						//printf("adding %lld ", subtr[j]);
					}
						//printf("\nsum %lld\n",sum );
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

			printf("%lld\n",ans);
	}
}