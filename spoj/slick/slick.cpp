#include <bits/stdc++.h>
using namespace std;

int arr[250][250];
int visit[250][250];

map<int,int> hash;
priority_queue<int> minheap;

int bfs(int m,int n,int x,int y){
	queue<int> q_x;
	queue<int> q_y;

	q_x.push(x);
	q_y.push(y);
	visit[x][y]=1;

	int count=0;

	while(!q_x.empty()){
		int temp_x=q_x.front();
		int temp_y=q_y.front();
		q_x.pop();
		q_y.pop();

		count++;

		if(temp_x-1>=0 && arr[temp_x-1][temp_y]==1 && visit[temp_x-1][temp_y]==0){
			q_x.push(temp_x-1);
			q_y.push(temp_y);
			visit[temp_x-1][temp_y]=1;
		}

		if(temp_x+1<m && arr[temp_x+1][temp_y]==1 && visit[temp_x+1][temp_y]==0){
			q_x.push(temp_x+1);
			q_y.push(temp_y);
			visit[temp_x+1][temp_y]=1;
		}

		if(temp_y-1>=0 && arr[temp_x][temp_y-1]==1 && visit[temp_x][temp_y-1]==0){
			q_x.push(temp_x);
			q_y.push(temp_y-1);
			visit[temp_x][temp_y-1]=1;
		}

		if(temp_y+1<n && arr[temp_x][temp_y+1]==1 && visit[temp_x][temp_y+1]==0){
			q_x.push(temp_x);
			q_y.push(temp_y+1);
			visit[temp_x][temp_y+1]=1;
		}

	}

	return count;
}

int bfs_loop(int m,int n){

	int parts=0;

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1 && visit[i][j]==0){
				int temp=bfs(m,n,i,j);
				parts++;

				if(hash[temp]==0){
					hash[temp]=1;
					minheap.push(temp*(-1));
				}else{
					hash[temp]=hash[temp]+1;
				}

				//printf("temp is %d, hash is %d\n",temp,hash[temp]);
			}
		}
	}

	printf("%d\n",parts);

	return 0;
}

int main(int argc, char const *argv[])
{
	int i,j,t,n,m,k;

	while(1){
		scanf("%d%d",&m,&n);
		if(n==0&&m==0){
			break;
		}

		hash.clear();

		for(j=0;j<250;j++){
			for(k=0;k<250;k++){
				arr[j][k]=-1;
				visit[j][k]=0;
			}
		}

		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				scanf("%d",&arr[j][k]);
			}
		}

		// process

		bfs_loop(m,n);

		while(!minheap.empty()){
			printf("%d %d\n",minheap.top()*(-1),hash[minheap.top()*(-1)]);
			minheap.pop();
		}
	}

	return 0;
}