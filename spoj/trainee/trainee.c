#include <stdio.h>

int main(){
	typedef long long lg;
	lg times,sum,rem1,rem2,count,i,j,k,e,n;
	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld%lld",&e,&n);

		sum=(e+n)/3;

		if(e<n){
			count=e;
		}else{
			count=n;
		}

		if(sum>count){
			sum=count;
		}

		printf("%lld\n",sum);

	}
}