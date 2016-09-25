#include <bits/stdc++.h>
using namespace std;

char arr[101][101];
int visit[101][101];
int parent[101][101];	// for indexed only

//   ALLIZZWELL (0,9)

char match[11]={'A','L','L','I','Z','Z','W','E','L','L','\0'};	//"ALLIZZWELL"

int dfs_redefined(int row,int col,int j,int k,int index){
	if(index==9){
		return 9;
	}

	//printf("visited %c at %d %d, index %d\n",arr[j][k],j,k,index );

	visit[j][k]=1;

	if( ((j-1)>=0) && (k>=0) && (visit[j-1][k]==0) && (arr[j-1][k]==match[index+1]) ){
		int rt=dfs_redefined(row,col,j-1,k,index+1);

		if(rt==-1){
			visit[j-1][k]=0;
		}else{
			return rt;
		}
	}

	if( ((j+1)<row) && (k>=0) && (visit[j+1][k]==0) && (arr[j+1][k]==match[index+1]) ){
		int rt=dfs_redefined(row,col,j+1,k,index+1);

		if(rt==-1){
			visit[j+1][k]=0;
		}else{
			return rt;
		}
	}

	if( ((j)>=0) && (k-1>=0) && (visit[j][k-1]==0) && (arr[j][k-1]==match[index+1]) ){
		int rt=dfs_redefined(row,col,j,k-1,index+1);

		if(rt==-1){
			visit[j][k-1]=0;
		}else{
			return rt;
		}
	}

	if( ((j)>=0) && (k+1<col) && (visit[j][k+1]==0) && (arr[j][k+1]==match[index+1]) ){
		int rt=dfs_redefined(row,col,j,k+1,index+1);

		if(rt==-1){
			visit[j][k+1]=0;
		}else{
			return rt;
		}
	}



	if( ((j-1)>=0) && (k-1>=0) && (visit[j-1][k-1]==0) && (arr[j-1][k-1]==match[index+1]) ){
		int rt=dfs_redefined(row,col,j-1,k-1,index+1);

		if(rt==-1){
			visit[j-1][k-1]=0;
		}else{
			return rt;
		}
	}

	if( ((j-1)>=0) && (k+1<col) && (visit[j-1][k+1]==0) && (arr[j-1][k+1]==match[index+1]) ){
		int rt=dfs_redefined(row,col,j-1,k+1,index+1);

		if(rt==-1){
			visit[j-1][k+1]=0;
		}else{
			return rt;
		}
	}

	if( ((j+1)<row) && (k-1>=0) && (visit[j+1][k-1]==0) && (arr[j+1][k-1]==match[index+1]) ){
		int rt=dfs_redefined(row,col,j+1,k-1,index+1);

		if(rt==-1){
			visit[j+1][k-1]=0;
		}else{
			return rt;
		}
	}

	if( ((j+1)<row) && (k+1<col) && (visit[j+1][k+1]==0) && (arr[j+1][k+1]==match[index+1]) ){
		int rt=dfs_redefined(row,col,j+1,k+1,index+1);

		if(rt==-1){
			visit[j+1][k+1]=0;
		}else{
			return rt;
		}
	}

	return -1;
	
}

int main(int argc, char const *argv[])
{
	int t,r,c,i,j,k;
	scanf("%d",&t);

	for(i=0;i<t;i++){
		scanf("%d%d",&r,&c);

		for(j=0;j<101;j++){
			for(k=0;k<101;k++){
				visit[j][k]=0;
				parent[j][k]=0;
			}
		}

		for(j=0;j<r;j++){
			for(k=0;k<c;k++){
				cin>>arr[j][k];
			}
		}

		int flag=0;

		for(j=0;j<r;j++){
			for(k=0;k<c;k++){
				
				if(arr[j][k]=='A'){
					int rt=dfs_redefined(r,c,j,k,0);

					if(rt==-1){
						continue;
					}else{
						flag=1;
						break;
					}
				}

			}

			if(flag==1){
				break;
			}
		}

		if(flag==1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}

	return 0;
}