#include <bits/stdc++.h>
using namespace std;

int main()
{
	typedef long long lg;
	lg times,i,j,k,p,n,m;
	scanf("%lld",&times);
	
	for(i=0;i<times;i++){

		scanf("%lld%lld",&n,&m);

		lg count[n],parent[n];

		for(j=0;j<n;j++){
			count[j]=0;
		}

		for(j=0;j<m;j++){
			
			lg t1,t2;
			scanf("%lld%lld",&t1,&t2);

			count[t1-1]++;
			count[t2-1]++;

			if(count[t1-1]==1){
				parent[t1-1]=t2-1;
			}else{
				parent[t1-1]=-1;
			}

			if(count[t2-1]==1){
				parent[t2-1]=t1-1;
			}else{
				parent[t2-1]=-1;
			}

		}

		int flag=0;

		for(j=0;j<n;j++){
			
			if(parent[j]!=-1){
				if(count[j]==1 && count[parent[j]]>=3){
					flag=-1;
					break;
				}
			}

		}	

		if(flag==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}

	return 0;
}


/*
3
3 2
1 2
2 3
4 3
1 2
2 3
2 4
6 7
1 2
1 3
2 3
2 4
4 5
4 6
5 6
*/