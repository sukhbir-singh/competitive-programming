#include <bits/stdc++.h>
using namespace std;

int main()
{
	typedef long long lg;
	lg times,i,j,k,p,n;
	scanf("%lld",&times);
	
	for(i=0;i<times;i++){

		scanf("%lld",&p);

		int points[p];

		for(j=0;j<p;j++){

			scanf("%lld",&n);

			int count[6]={0,0,0,0,0,0};

			points[j]=n;
			int arr[n],temp;

		
			for(k=0;k<n;k++){
				scanf("%d",&temp);

				count[temp-1]=count[temp-1]+1;
			}

			/*printf("count: ");
			for(k=0;k<6;k++){
				printf("%d ",count[k]);
			}
			printf("\n");*/

			int types=0;

			for(k=0;k<6;k++){
				if(count[k]!=0){
					types++;
				}
			}

			int zeros=0;

			while(zeros<=2){
				zeros=0;

				for(k=0;k<6;k++){
					if(count[k]==0){
						zeros++;
					}else{
						count[k]=count[k]-1;
					}
				}

				if(zeros==0){
					points[j]=points[j]+4;
				}else if(zeros==1){
					points[j]=points[j]+2;
				}else if(zeros==2){
					points[j]=points[j]+1;
				}
			}

			//printf("points:  %d\n",points[j] );

			/*if(types>=6){
				points[j]=points[j]+4;
			}else if(types==5){
				points[j]=points[j]+2;
			}else if(types==4){
				points[j]=points[j]+1;
			}*/

		}

		int max=-1;		
		int winner=-1;
		int index=0;

		for(j=0;j<p;j++){
			if(points[j]>max){
				max=points[j];
				index=j;
			}
		}

		winner=index;

		for(j=0;j<p;j++){
			if(points[j]==max && j!=winner){
				winner=-1;
				break;
			}
		}

		if(winner==-1){
			printf("tie\n");
		}else if(winner==0){
			printf("chef\n");
		}else{
			printf("%d\n",winner+1);
		}

	}

	return 0;
}


/*
Input:
3
2
6 1 2 3 4 5 6
9 3 3 3 4 4 4 5 5 5
2
5 2 3 4 5 6
7 1 1 2 2 3 3 4
3
4 1 1 2 3
4 1 2 2 3
4 1 2 3 3

Output:
chef
2
tie

*/