#include <stdio.h>

int main(){
	typedef long long lg;

	lg times,temp,n,i,j,k,power=1;
	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld",&n);

		power=1;
		temp=2;

		while(1){

			if(temp>=n+2){
				break;
			}
			temp=temp*2;
			power++;
		}

		//printf("%lld - %lld\n",n,power-1);
		printf("%lld ",n );

		  for(j=power-2;j>=0;j--)
		  {
		    temp=1<<j;
		    if((temp&(n))==0)
		    {
		      //a[7-j]='0';
		    	printf("0");
		    }
		    else {
		    	//a[7-j]='1';
		    	printf("1");
		    }

		  }

		  printf("\n");

	}

	return 0;
}