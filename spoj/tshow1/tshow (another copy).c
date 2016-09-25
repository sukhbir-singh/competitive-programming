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
			//if(n==1){power++; break;}

			if(temp>=n+1){
				break;
			}
			temp=temp*2;
			power++;
		}

		//printf("( 2 ^ %lld ) >=  %lld , so for %lld, digits required are %lld\n",power,n,n,power-1);
		
		printf("%lld - %lld\n",n,power);


		

		  /*for(i=0;i<=7;i++)
		  {
		    temp=t<<i;
		    if((temp&n)==0)
		    {
		      a[7-i]='0';
		    }
		    else a[7-i]='1';

		    
		  }

		  printf("%s\n",a);*/

	}

	return 0;
}