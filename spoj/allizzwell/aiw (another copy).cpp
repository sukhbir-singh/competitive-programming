#include <bits/stdc++.h>
using namespace std;

char arr[101][101];
int visit[101][101];
int parent[101][101];	// for indexed only

//   ALLIZZWELL (0,9)

char match[11]={'A','L','L','I','Z','Z','W','E','L','L','\0'};	//"ALLIZZWELL"

int dfs_execute(int row,int col,int j, int k){ 
	stack<int> x_st;
	stack<int> y_st;

	x_st.push(j); 
	y_st.push(k);

	visit[j][k]=1;
	parent[j][k]=0;

	int max=0;

	//printf("col %d row %d\n",j,k );

	while(!x_st.empty()){
		int x_temp=x_st.top();
		int y_temp=y_st.top();

		x_st.pop();
		y_st.pop();

		int found=0;
		int parent_index=parent[x_temp][y_temp];
		printf("poped %d %d\n",x_temp,y_temp);


		if(parent_index>max){
			max=parent_index;
		}

		if(parent_index==9){
			break;
		}

		if( ((x_temp-1)>=0) && (y_temp>=0) && (visit[x_temp-1][y_temp]==0) && (arr[x_temp-1][y_temp]==match[parent_index+1]) ){
			x_st.push(x_temp-1);
			y_st.push(y_temp);
			parent[x_temp-1][y_temp]=parent_index+1;
			visit[x_temp-1][y_temp]=1;

			printf("pushed %d %d\n",x_temp-1,y_temp);
		}

		if( ((x_temp+1)<row) && (y_temp>=0) && (visit[x_temp+1][y_temp]==0) && (arr[x_temp+1][y_temp]==match[parent_index+1]) ){
			x_st.push(x_temp+1);
			y_st.push(y_temp);
			parent[x_temp+1][y_temp]=parent_index+1;
			visit[x_temp+1][y_temp]=1;

			printf("pushed %d %d\n",x_temp+1,y_temp);
		}

		if( ((x_temp)>=0) && (y_temp-1>=0) && (visit[x_temp][y_temp-1]==0) && (arr[x_temp][y_temp-1]==match[parent_index+1]) ){
			x_st.push(x_temp);
			y_st.push(y_temp-1);
			parent[x_temp][y_temp-1]=parent_index+1;
			visit[x_temp][y_temp-1]=1;

			printf("pushed %d %d\n",x_temp,y_temp-1);
		}

		if( ((x_temp)<col) && (y_temp+1<col) && (visit[x_temp][y_temp+1]==0) && (arr[x_temp][y_temp+1]==match[parent_index+1]) ){
			x_st.push(x_temp);
			y_st.push(y_temp+1);
			parent[x_temp][y_temp+1]=parent_index+1;
			visit[x_temp][y_temp+1]=1;

			printf("pushed %d %d\n",x_temp,y_temp+1);
		}



		if( ((x_temp-1)>=0) && (y_temp-1>=0) && (visit[x_temp-1][y_temp-1]==0) && (arr[x_temp-1][y_temp-1]==match[parent_index+1]) ){
			x_st.push(x_temp-1);
			y_st.push(y_temp-1);
			parent[x_temp-1][y_temp-1]=parent_index+1;
			visit[x_temp-1][y_temp-1]=1;

			printf("pushed %d %d\n",x_temp-1,y_temp-1);
		}

		if( ((x_temp-1)>=0) && (y_temp+1<col) && (visit[x_temp-1][y_temp+1]==0) && (arr[x_temp-1][y_temp+1]==match[parent_index+1]) ){
			x_st.push(x_temp-1);
			y_st.push(y_temp+1);
			parent[x_temp-1][y_temp+1]=parent_index+1;
			visit[x_temp-1][y_temp+1]=1;

			printf("pushed %d %d\n",x_temp-1,y_temp+1);
		}

		if( ((x_temp+1)<row) && (y_temp-1>=0) && (visit[x_temp+1][y_temp-1]==0) && (arr[x_temp+1][y_temp-1]==match[parent_index+1]) ){
			x_st.push(x_temp+1);
			y_st.push(y_temp-1);
			parent[x_temp+1][y_temp-1]=parent_index+1;
			visit[x_temp+1][y_temp-1]=1;

			printf("pushed %d %d\n",x_temp+1,y_temp-1);
		}

		if( ((x_temp+1)<row) && (y_temp+1<col) && (visit[x_temp+1][y_temp+1]==0) && (arr[x_temp+1][y_temp+1]==match[parent_index+1]) ){
			x_st.push(x_temp+1);
			y_st.push(y_temp+1);
			parent[x_temp+1][y_temp+1]=parent_index+1;
			visit[x_temp+1][y_temp+1]=1;

			printf("pushed %d %d\n",x_temp+1,y_temp+1);
		}
	
	}

	return max;	// 9 - YES , else - NO

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
					int rt=dfs_execute(r,c,j,k);
					printf("returned %d\n",rt );

					if(rt==9){
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