#include <stdio.h>

int main(){
	typedef long long lg;

	lg times,temp,n,i,j,k,m;
	scanf("%lld",&times);

	for(i=0;i<times;i++){

		m=0;

		scanf("%lld%lld",&n,&k);

		  for(j=0;j<n;j++){
		  	scanf("%lld",&temp);
		  	if(temp==-1){
		  		m++;
		  	}
		  }

		  if(k>=m){
		  	k=k-m;

		  	//printf("n: %lld\n",n);

		  	if(k%2==0){
		  		printf("%lld\n",n);
		  	}else{
		  		printf("%lld\n",n-2);
		  	}
		  }else{
		  	//k<m
		  	m=m-k;
		  	printf("%lld\n",n-2*m);
		  }

	}

	return 0;
}