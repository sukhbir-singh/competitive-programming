#include <bits/stdc++.h>

int main()
{
	int n,c,i,j;
	scanf("%d%d",&n,&c);

	int arr[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	int pr=0;
	int count=0;

	for(i=0;i<n;i++){
		if(arr[i]-pr<=c){
			count++;
		}else{
			count=1;
		}

		pr=arr[i];
	}

	printf("%d\n",count );	

return 0;
}