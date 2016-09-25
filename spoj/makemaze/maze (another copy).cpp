#include <bits/stdc++.h>
using namespace std;

char arr[20][20];
int visit[20][20];

int x11=0;
int y11=0;
int x22=0;
int y22=0;

int shallow_check(int m,int n){
	int i,count=0;

	for(i=0;i<n;i++){
		
		if(arr[0][i]=='.'){
			count++;

			if(count==1){
				x11=0;
				y11=i;
			}else if(count==2){
				x22=0;
				y22=i;
			}

			//printf("count at %d %d\n",0,i );
		}

		if(arr[m-1][i]=='.' && (m-1)!=0){
			count++;

			if(count==1){
				x11=m-1;
				y11=i;
			}else if(count==2){
				x22=m-1;
				y22=i;
			}

			//printf("count at %d %d\n",m-1,i );
		}

		if(count>2){
			break;
		}
	}

	for(i=1;i<m-1;i++){

		if(count>2){
			break;
		}
		
		if(arr[i][0]=='.'){
			count++;

			if(count==1){
				x11=i;
				y11=0;
			}else if(count==2){
				x22=i;
				y22=0;
			}

			//printf("count at %d %d\n",i,0 );
		}

		if(arr[i][n-1]=='.' && (n-1)!=0){
			count++;

			if(count==1){
				x11=i;
				y11=n-1;
			}else if(count==2){
				x22=i;
				y22=n-1;
			}

			//printf("count at %d %d\n",i,n-1 );
		}

	}

	if(count>2){
		return count;	
	}
		return 0;
}

int execute(int m,int n){
	queue<int> x_q;
	queue<int> y_q;

	x_q.push(x11);
	y_q.push(y11);
	visit[x11][y11]=1;

	int check=0;

	while(!x_q.empty() && !y_q.empty()){
		int temp_x=x_q.front();
		int temp_y=y_q.front();

		if(temp_x==x22 && temp_y==y22){
			check=1; break;
		}

		x_q.pop();
		y_q.pop();

		if(temp_x-1>=0 && arr[temp_x-1][temp_y]=='.' && visit[temp_x-1][temp_y]==0){
			x_q.push(temp_x-1);
			y_q.push(temp_y);
			visit[temp_x-1][temp_y]=1;
		}

		if(temp_x+1<m && arr[temp_x+1][temp_y]=='.' && visit[temp_x+1][temp_y]==0){
			x_q.push(temp_x+1);
			y_q.push(temp_y);
			visit[temp_x+1][temp_y]=1;
		}

		if(temp_y-1>=0 && arr[temp_x][temp_y-1]=='.' && visit[temp_x][temp_y-1]==0){
			x_q.push(temp_x);
			y_q.push(temp_y-1);
			visit[temp_x][temp_y-1]=1;
		}

		if(temp_y+1<n && arr[temp_x][temp_y+1]=='.' && visit[temp_x][temp_y+1]==0){
			x_q.push(temp_x);
			y_q.push(temp_y+1);
			visit[temp_x][temp_y+1]=1;
		}

	}

	if(check==1){
		return 1;	// valid
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	int i,j,t,n,m,k;
	scanf("%d",&t);

	for(i=0;i<t;i++){
		scanf("%d%d ",&m,&n);

		for(j=0;j<20;j++){
			for(k=0;k<20;k++){
				arr[j][k]=0;
				visit[j][k]=0;
			}
		}

		x11=0;
		y11=0;
		x22=0;
		y22=0;

		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				cin>>arr[j][k];
			}
		}

		int rt=shallow_check(m,n);

		if(rt!=0){
			printf("invalid\n");
			continue;
		}

		//printf("exits	 %d %d, %d %d\n",x11,y11,x22,y22);

		if(execute(m,n)==1){
			printf("valid\n");
		}else{
			printf("invalid\n");
		}
	}

	return 0;
}