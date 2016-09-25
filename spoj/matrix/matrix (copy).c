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
	
	lg queries,k;
	/*scanf("%lld",&queries);

	for(k=0;k<queries;k++){
		char ch;
		int ii,jj,kk;
		
		scanf(" %c%lld%lld%lld",&ch,&ii,&jj,&kk);

		printf("%c %lld %lld %lld",ch,ii,jj,kk );
	}*/

	for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
       //mm.arr[i][j]=arr[i][j]-m.arr[i][j];
       for(int k=0;k<n;k++)
       {
         sum+=a[i][k]*b[k][j];
       }
     }
   }

   printf("Sum: %lld\n", sum);

}