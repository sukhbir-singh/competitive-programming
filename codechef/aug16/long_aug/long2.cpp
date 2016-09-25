#include <bits/stdc++.h>

void print(long long  arr[],long long  jump[],long long  count[],long long  visited[],long long n){
	printf("\nArr: ");
	for(long long i=0;i<n;i++){
		printf("%lld ",arr[i]);
	}

	printf("\nJump: ");
	for(long long  i=0;i<n;i++){
		printf("%lld ",jump[i]);
	}

	printf("\nCount: ");
	for(long long i=0;i<n;i++){
		printf("%lld ",count[i]);
	}

	printf("\nVisited: ");
	for(long long i=0;i<n;i++){
		printf("%lld ",visited[i]);
	}

	printf("\n\n");
}

int main()
{
	typedef long long lg;
	lg times,n,i,j;
	lg a,b;
	scanf("%lld",&times);
	
	for(i=0;i<times;i++){
		scanf("%lld",&n);

		lg arr[n],jump[n],count[n],visited[n];

		for(lg j=0;j<n;j++){
			scanf("%lld",&arr[j]);
			jump[j]=(j+arr[j]+1)%n;
			count[j]=0;
			visited[j]=-1;
		}

		//print(arr,jump,count,visited,n);

		lg ans=0;

		for(lg j=0;j<n;j++){
			if(visited[j]==-1){
				int flag=0;

				lg temp=j;

				while(flag==0){
					count[temp]++;
					visited[temp]=1;

					if(count[temp]>=3){
						flag=1;
						break;
					}

					if(count[temp]==2){
						ans++;
					}
					
					temp=jump[temp];

				}
			}
		}

		printf("%lld\n",ans);

	}

return 0;
}
/*
3
4
1 1 1 1
4
3 0 0 0
4
0 0 0 2
Output:
4
1
2
*/
