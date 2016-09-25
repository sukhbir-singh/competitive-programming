#include <stdio.h>

void tobinary(int n,char a[])
{
  

//  printf("In Binary : %s \n",a);
}

int main(){
	typedef long long lg;

	lg times,n,i,j,k;
	scanf("%lld",&times);

	  char a[8]={'0','0','0','0','0','0','0','0'};

	for(i=0;i<times;i++){
		scanf("%lld",&n);

		int i=0,t=1,temp=0;
		  for(i=0;i<=7;i++)
		  {
		    temp=t<<i;
		    if((temp&n)==0)
		    {
		      a[7-i]='0';
		    }
		    else a[7-i]='1';

		    
		  }

		  printf("%s\n",a);

	}

	return 0;
}