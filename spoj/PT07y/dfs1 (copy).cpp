#include <bits/stdc++.h>
using namespace std;

int arr[10001][10001];
int visit[10001];


int dfs(int n){
	stack<int> st;
	st.push(1);
	visit[1]=1;
	int count=0;

	while(!st.empty()){
		int top=st.top();
		st.pop();
		count=0;

		for(int i=1;i<=n;i++){

			if(arr[top][i]==1){
				if(visit[i]==0){
					st.push(i);
					visit[i]=1;
				}else{
					count++;
				}

				if(count>=2){
					break;
				}
			}
		}

		if(count>=2){
			break;
		}
	}

	if(count>=2){
		return 2;	// not a tree
	}

	return 0;	// tree
}


int main(int argc, char const *argv[])
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		arr[u][v]=1;
		arr[v][u]=1;
	}

	int t=dfs(n);

	if(t>=2){
		printf("NO\n");
	}else{
		int temp=0;
		
		for(int i=1;i<=n;i++){
			if(visit[i]==0){
				temp=1;
				break;
			}
		}

		if(temp==1){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
	}

	return 0;
}