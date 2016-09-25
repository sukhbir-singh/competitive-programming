#include <stdio.h>
#include <stdlib.h>
//int arr[100000000];

int main()
{
	typedef long long lg;
	lg times,i,j,k,n,s,e;
	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld",&n);

		//for(j=0;j<100000;j++) arr[j]=0;
		int *arr=(int *)calloc(1000000,sizeof(int));

		lg max=0;

		for(j=0;j<n;j++){
			scanf("%lld%lld",&s,&e);

			for(k=s;k<e;k++){
				arr[k]++;
				if(max<arr[k]) max=arr[k];
			}
		}

		printf("%lld\n",max);

	}


}