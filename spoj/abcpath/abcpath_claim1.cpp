#include <bits/stdc++.h>
using namespace std;

char arr[51][51];
int visit[51][51];
int level[51][51];

int dfs_execute(int h,int w,int x,int y){
	stack<int> x_st;
	stack<int> y_st;

	x_st.push(x);
	y_st.push(y);

	level[x][y]=1;
	visit[x][y]=1;

	char max_char='A';

	while(!x_st.empty()){
		int temp_x=x_st.top();
		int temp_y=y_st.top();

		x_st.pop();
		y_st.pop();

		if(arr[temp_x][temp_y]>max_char){
			max_char=arr[temp_x][temp_y];
		}

		// 8 conditions

		if((temp_x-1)>=1 && (temp_y-1)>=1 && arr[temp_x-1][temp_y-1]==(arr[temp_x][temp_y]+1)){
			x_st.push(temp_x-1);
			y_st.push(temp_y-1);
		}

		if((temp_x)>=1 && (temp_y-1)>=1 && arr[temp_x][temp_y-1]==(arr[temp_x][temp_y]+1)){
			x_st.push(temp_x);
			y_st.push(temp_y-1);
		}

		if((temp_x+1)<=w && (temp_y-1)>=1 && arr[temp_x+1][temp_y-1]==(arr[temp_x][temp_y]+1)){
			x_st.push(temp_x+1);
			y_st.push(temp_y-1);
		}

		//
		if((temp_x-1)>=1 && (temp_y)>=1 && arr[temp_x-1][temp_y]==(arr[temp_x][temp_y]+1)){
			x_st.push(temp_x-1);
			y_st.push(temp_y);
		}

		if((temp_x+1)<=w && (temp_y)>=1 && arr[temp_x+1][temp_y]==(arr[temp_x][temp_y]+1)){
			x_st.push(temp_x+1);
			y_st.push(temp_y);
		}
		
		//
		if((temp_x-1)>=1 && (temp_y+1)>=1 && arr[temp_x-1][temp_y+1]==(arr[temp_x][temp_y]+1)){
			x_st.push(temp_x-1);
			y_st.push(temp_y+1);
		}

		if((temp_x)>=1 && (temp_y+1)>=1 && arr[temp_x][temp_y+1]==(arr[temp_x][temp_y]+1)){
			x_st.push(temp_x);
			y_st.push(temp_y+1);
		}

		if((temp_x+1)<=w && (temp_y+1)>=1 && arr[temp_x+1][temp_y+1]==(arr[temp_x][temp_y]+1)){
			x_st.push(temp_x+1);
			y_st.push(temp_y+1);
		}		
	}

	int diff=max_char-'A'+1;
	//printf("max_char: %c, diff %d\n",max_char,diff);

	return diff;
}

int main(int argc, char const *argv[])
{
	int h,w,i,j,k;
	int case1=0;

	while(1){
		case1++;

		scanf("%d%d",&h,&w);
		if(h==0 && w==0){
			break;
		}

		for(int j=1;j<=h;j++){
			for(int k=1;k<=w;k++){
				cin>>arr[j][k];
			}
		}

		int max=0;

		for(int j=1;j<=h;j++){
			for(int k=1;k<=w;k++){
				if(arr[j][k]=='A'){
					int t=dfs_execute(h,w,j,k);

					if(t>max){
						max=t;
					}

				}
			}	
		}

		printf("Case %d: %d\n",case1,max);

	}


	return 0;
}