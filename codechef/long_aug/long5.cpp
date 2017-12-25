#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000
int sieve[MAX];

int main()
{
	int times,i,j,k,p,n,m;
	scanf("%d",&times);

	
   sieve[0]=1;
   sieve[1]=1;
   int count=0;

   for(i=2;i<MAX;i++){

		if(sieve[i]==0){
			sieve[i]=i;
		}

		for(j=i;j<MAX;j+=i){
			if(sieve[j]==0){
				sieve[j]=i;
			}
		}

   }

   ///

	for(i=0;i<times;i++){

		scanf("%d%d",&n,&m);

		int arr[n];
		int rs[m];
		count=0;

		for(j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}

		for(j=0;j<m;j++){

			int l,r,p;
			scanf("%d%d%d",&p,&l,&r);

			if(p==0){
				
				for(k=l-1;k<r;k++){
					//printf("p1 %d %d %d\n",prime_c,sieve[arr[k]],k);

					arr[k]=arr[k]/sieve[arr[k]];	//
				}

			}else{
				int max=1;
				//printf("hi1\n");


				for(k=l-1;k<r;k++){
					// int max=result;

					int temp=sieve[arr[k]];	//

					if(temp>max){
						max=temp;
					}

					// result=max;
				}

				rs[count++]= max;
				//printf("%d ",result );				
			}
		}

		for(j=0;j<count;j++){
			printf("%d ",rs[j]);
		}

		printf("\n");

	}

	return 0;
}


/*
Input: 

2
6 7
2 5 8 10 3 44
1 2 6
0 2 3
1 2 6
0 4 6
1 1 6
0 1 6
1 4 6
2 2
1 3
0 2 2
1 1 2

Output:
5 3 5 11
1
*/