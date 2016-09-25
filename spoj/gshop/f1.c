#include <stdio.h>

int main(){
	typedef long long lg;
	lg neg,total,magnitute_total,times,n,i,i1,j,k;

	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld%lld",&n,&k);
		lg arr[n];
		total=0,magnitute_total=0,neg=0;

		for(j=0;j<n;j++){
			scanf("%lld",&arr[j]);

			total+=arr[j];

			if(arr[j]>=0){
				magnitute_total+=arr[j];
			}else{
				neg++;
				magnitute_total-=arr[j];
			}
		}

		if(magnitute_total==0){
			printf("%lld\n",magnitute_total);
		}else if(k<neg){
			lg temp=0;
			for(i1=0;i1<k;i1++){
				temp=temp-arr[i1];
			}

			printf("%lld\n", total+2*temp);

		}else if(neg==0){
			if(k%2==0){
				printf("%lld\n", total);
			}else{
				printf("%lld\n", total-2*arr[0]);
			}
		}else{

			if((k-neg)%2==0){
				printf("%lld\n", magnitute_total);
			}else{

				lg minimum=arr[neg];
				if((-1)*arr[neg-1] < minimum ){minimum=(-1)*arr[neg-1]; }

				printf("%lld\n", magnitute_total-2*minimum);
			}

		}
	}

}