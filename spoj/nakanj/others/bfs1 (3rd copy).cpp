#include<bits/stdc++.h>
using namespace std;
int total=999999999;

int arr[8][8];
queue<char*> q;

void visit(char a[]){
	printf("visited %s\n",a);
	arr[a[0]-'a'][a[1]-'1']=1;
}

int check(char a[]){
	return arr[a[0]-'a'][a[1]-'1'];
}

void bfs(char a[],char b[],int steps){
	// d4    e2 e6 f5 f3 c2 c6 b3 b5
	q.push(a);

	while(!q.empty()){  
		char* aa=q.front();
		printf("&&%s\n",aa);

		q.pop();
		visit(aa);

		if(aa[0]==b[0] && aa[1]==b[1]){
			printf("Answer : %d\n",steps);
			break;
		}

		if(aa[0]+1 <='h'){		
			if(aa[1]+2<='8'){
				char temp[3];
				temp[0]=aa[0]+1;

		    	printf("$$1 %s , %c\n",aa, aa[1] );

				temp[1]=aa[1];
				temp[1]+=2;

		    printf("$$2 %s , %c\n",aa, aa[1] );

				temp[2]='\0';
				//printf("%s\n",temp);
				if(check(temp)==0){
					q.push(temp);   printf("pushed1 : %s\n",temp);
				}	
		    }

		    //printf("$$ %s , %c\n",aa, aa[1] );

			if(aa[1]-2>='1'){
				char temp[3];
				temp[0]=aa[0]+1;
				temp[1]=aa[1]-2;
				temp[2]='\0';
				//printf("%s\n",temp);
				if(check(temp)==0){	
					q.push(temp);   printf("pushed2 : %s\n",temp);
				 }	
			}
		}

	if(aa[0]+2 <='h'){
		
		if(aa[1]+1<='8'){
			char temp[3];
			temp[0]=aa[0]+2;
			temp[1]=aa[1]+1;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   printf("pushed3 : %s\n",temp);
			}
		
		}

		if(aa[1]-1>='1'){
			char temp[3];
			temp[0]=aa[0]+2;
			temp[1]=aa[1]-1;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){			
				q.push(temp);   printf("pushed4 : %s\n",temp);
			}

		}
	}

	if(aa[0]-2 >='a'){
		
		if(aa[1]+1<='8'){
			char temp[3];
			temp[0]=aa[0]-2;
			temp[1]=aa[1]+1;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   printf("pushed5 : %s\n",temp);
			}
		
		}

		if(aa[1]-1>='1'){
			char temp[3];
			temp[0]=aa[0]-2;
			temp[1]=aa[1]-1;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   printf("pushed6 : %s\n",temp);
			}

		}
	}

	if(aa[0]-1 >='a'){
		
		if(aa[1]+2<='8'){	
			char temp[3];
			temp[0]=aa[0]-1;
			temp[1]=aa[1]+2;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   printf("pushed7 : %s\n",temp);
			}
		
		}

		if(aa[1]-2>='1'){
			char temp[3];
			temp[0]=aa[0]-1;
			temp[1]=aa[1]-2;
			temp[2]='\0';
			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   printf("pushed8 : %s\n",temp);
			}

		}

	}

	steps++;

   }	 //while ends

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