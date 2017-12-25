#include <bits/stdc++.h>

int main()
{
	int times,i,j,n;
	char ch[4];
	scanf("%d",&times);
	
	for(i=0;i<times;i++){
		scanf("%d",&n);
		int arr[n];

		scanf("%s",ch);

		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}

		if(n!=1){
			printf("Dum\n");
		}else{
			if(ch[1]=='u'){
				printf("Dum\n");
			}else{
				if(arr[0]%2==0){
					printf("Dee\n");
				}else{
					printf("Dum\n");	
				}
			}
		}
		
	}

return 0;
}
/*
1
2 Dee
2 2
*/