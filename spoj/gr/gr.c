#include <stdio.h>

int main(){
	typedef long long lg;
	lg times,m,n,t,i,i1,j,k;

		scanf("%lld%lld",&n,&t);

		lg arr[n][n],temp=1;

		for(i1=0;i1<n;i1++){
			for(j=0;j<n;j++){
				arr[i1][j]=temp++;				
			}
		}

		lg start1=0,start2=0;

		if(t%4==0){
			printf("Atef\n");
			for(i1=0;i1<n;i1++){
			for(j=0;j<n;j++){
				printf("%lld ",arr[i1][j]);
			}
			printf("\n");
			}
		}else if(t%4==1){
			printf("Sameh\n");
			for(i1=0;i1<n;i1++){
			for(j=n-1;j>=0;j--){
				printf("%lld ",arr[j][i1]);
			}
			printf("\n");
			}
		}else if(t%4==2){
			printf("Ameen\n");
			for(i1=n-1;i1>=0;i1--){
			for(j=n-1;j>=0;j--){
				printf("%lld ",arr[i1][j]);
			}
			printf("\n");
			}
		}else if(t%4==3){
			printf("Shafeek\n");
			for(i1=n-1;i1>=0;i1--){
			for(j=0;j<n;j++){
				printf("%lld ",arr[j][i1]);
			}
			printf("\n");
			}
		}
}

/*
Ameen
Shafeek
Atef
Sameh
*/