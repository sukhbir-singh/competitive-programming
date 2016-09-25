#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a,const void *b){
	return  (*(long long*)b - *(long long*)a );
}

int main()
{
	typedef long long lg;
	lg times,i,j,j1,k,n;
	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld",&n);
		
		lg arr1[n],arr2[n],sum=0,count=0;

		for(j=0;j<n;j++)
		scanf("%lld",&arr1[j]);

		for(j1=0;j1<n;j1++)
		scanf("%lld",&arr2[j1]);

		lg subtr[n];

		for(j=0;j<n;j++){
			subtr[j]=arr1[j]-arr2[j];
		}

		qsort(subtr,n,sizeof(long long),cmpfunc);

		for(j=0;j<n;j++){
			sum+=subtr[j];
			if(sum>=0){
				count++;
			}else{
				break;
			}
		}

		printf("%lld\n",count);

	}
}