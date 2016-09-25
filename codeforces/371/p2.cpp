#include <bits/stdc++.h>
using namespace std;

int main()
{
	int times,i,j;

	scanf("%d",&times);

	int arr[times],total=0;

	int type[3];

	int count=0;
	int out_bound=0;

	for(i=0;i<times;i++){
		scanf("%d",&arr[i]);

		int present=0;

		for(j=0;j<count;j++){
			if(type[j]==arr[i]){
				present=1;
				break;
			}
		}

		if(present==0){

			if(count==3){
				out_bound=1;
				continue;
			}

			type[count++]=arr[i];

		}

	}

	//printf("##%lld %lld %lld##\n",type[0],type[1],type[2] );

	if(out_bound==1){
		printf("NO\n");
	}else{

		if(count==3){
			sort(type,type+3);

			if(type[1]-type[0] == type[2]-type[1]){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
			
		}else{
			printf("YES\n");
		}
	}

	
	return 0;
}