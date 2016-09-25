#include <stdio.h>


int main(){
	typedef long long lg;

	lg times,n,i,j,k,count;
	scanf("%lld",&times);

	for(i=0;i<times;i++){		
		scanf("%lld",&n);

		lg x=0,y=0,count=1;

		for(j=1;j<=n;j++){
			if(count==1){	
				x=x+j;
				count++;
			}else if(count==2){
				count++;
				y=y+j;
			}else if(count==3){
				count++;
				x=x-j;
			}else if(count==4){
				count=1;
				y=y-j;
			}
		}

		printf("%lld %lld\n",x,y );

	}
}