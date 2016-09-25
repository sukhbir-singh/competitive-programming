#include<bits/stdc++.h>
int total=999999999;

int arr[8][8];

void set(char a[]){
	arr[a[0]-'a'][a[1]-'1']=1;
}

void unset(char a[]){
	arr[a[0]-'a'][a[1]-'1']=0;
}

int check(char a[]){
	return arr[a[0]-'a'][a[1]-'1'];
}

void bfs(char a[],char b[],int steps){
	// d4    e2 e6 f5 f3 c2 c6 b3 b5
	set(a);

	if((a[0]==b[0])&&(a[1]==b[1])){
		if(steps<total){
			printf("value updated %d\n",steps);
			total=steps;	
		}		
		unset(a);
		return;
	}
	printf("# %s (%d) \n",a,steps);

	steps++;

	char temp[3];

	if(a[0]+1 <='h'){
		
		if(a[1]+2<='8'){

			temp[0]=a[0]+1;
			temp[1]=a[1]+2;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				bfs(temp,b,steps);	
			}
			
	
		}

		if(a[1]-2>='1'){

			temp[0]=a[0]+1;
			temp[1]=a[1]-2;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){	
				bfs(temp,b,steps);
			}	

		}
	}

	if(a[0]+2 <='h'){
		
		if(a[1]+1<='8'){

			temp[0]=a[0]+2;
			temp[1]=a[1]+1;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				bfs(temp,b,steps);
			}
		
		}

		if(a[1]-1>='1'){

			temp[0]=a[0]+2;
			temp[1]=a[1]-1;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){			
				bfs(temp,b,steps);
			}

		}
	}

	if(a[0]-2 >='a'){
		
		if(a[1]+1<='8'){

			temp[0]=a[0]-2;
			temp[1]=a[1]+1;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				bfs(temp,b,steps);
			}
		
		}

		if(a[1]-1>='1'){

			temp[0]=a[0]-2;
			temp[1]=a[1]-1;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				bfs(temp,b,steps);
			}

		}
	}

	if(a[0]-1 >='a'){
		
		if(a[1]+2<='8'){

			temp[0]=a[0]-1;
			temp[1]=a[1]+2;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				bfs(temp,b,steps);
			}
		
		}

		if(a[1]-2>='1'){

			temp[0]=a[0]-1;
			temp[1]=a[1]-2;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				bfs(temp,b,steps);
			}

		}
	}

}

int main(){
	int times;
	scanf("%d",&times);

	char a[3],b[3];

	for(int i=0;i<times;i++){
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				arr[j][k]=0;
			}
		}

		total=999999999;

		scanf("%s%s",a,b);

		bfs(a,b,0);

		printf("Answer is %d\n", total);

	}
}

/*
Input:
3
a1 h8
a1 c2
h8 c3

Output:
6
1
4
*/