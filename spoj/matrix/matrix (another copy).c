#include <stdio.h>

int main(){
	typedef long long lg;
	lg n,i,j,sum=0;
	
	scanf("%lld",&n);
	int a[n][n],b[n][n];

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){scanf("%lld",&a[i][j]);}
	}	

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){scanf("%lld",&b[i][j]);}
	}	

	//initial calculate
	for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
       
       for(int k=0;k<n;k++)
       {
         sum+=a[i][k]*b[k][j];
       }
     }
   }

   printf("Default Sum: %lld\n", sum);
	
	lg queries,k;

	scanf("%lld",&queries);

	for(k=0;k<queries;k++){
		char ch;
		int ii,jj,kk;
		
		scanf(" %c%lld%lld%lld",&ch,&ii,&jj,&kk);

		//printf("%c %lld %lld %lld",ch,ii,jj,kk );

		if(ch=='A'){
			sum=sum - a[ii][jj]*b[jj][ii] + kk*b[ii][jj] ;
			printf("SUM: %lld\n", sum);
		}else{

			sum=sum - b[ii][jj]*a[jj][ii] + kk*a[ii][jj] ;
			printf("SUM: %lld\n", sum);
		}
	}

	

   

}