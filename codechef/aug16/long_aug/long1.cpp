#include <bits/stdc++.h>

int main()
{
	long long times,i,j;
	lg a,b;
	scanf("%lld",&times);
	
	for(i=0;i<times;i++)
	{
		scanf("%lld%lld",&a,&b);

		if(a%2==0 || b%2==0){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	
	}

return 0;
}
