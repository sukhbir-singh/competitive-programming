#include <stdio.h>


int main(){
	typedef long long lg;

	lg times,x,y,diff,n,i,j,k,count;
	scanf("%lld",&times);

	for(i=0;i<times;i++){		
		scanf("%lld",&n);
		
		if(n%4==0){
			x=-n/2;
			y=-n/2;
			//printf("$4$\n");
		}else {
			diff=n%4;
			if(diff>=2){
				if(diff==2){
					//printf("$2$\n");
					n=n+2;
					x=(n/2)-1;
					y=n/2;
				}else if(diff==3){
					//printf("$3$\n");
					n=n+1;
					x=-n/2;
					y=n/2;
				}
			}else{ 
				//printf("$1$\n");
					
					n=n-4;
					x=(n/2)+1;
					y=-n/2;
				}
		}

		printf("%lld %lld\n",x,y );

	}
}