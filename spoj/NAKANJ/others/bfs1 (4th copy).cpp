#include<bits/stdc++.h>
using namespace std;
int total=999999999;

int arr[8][8];
queue<string> q;

void visit(string a){
	cout<<"visited "<<a<<endl;
	arr[a.at(0)-'a'][a.at(1)-'1']=1;
}

int check(string a){
	return arr[a.at(0)-'a'][a.at(1)-'1'];
}

/*void bfs(string a,string b,int steps){
	// d4    e2 e6 f5 f3 c2 c6 b3 b5
	q.push(a);

	while(!q.empty()){  
		string aa=q.front();
		q.pop();
		visit(aa);

		if(aa.at(0)==b.at(0) && aa.at(1)==b.at(1)){
			printf("Answer : %d\n",steps);
			break;
		}

		if(aa.at(0)+1 <='h'){		
			if(aa.at(1)+2<='8'){

				string temp;
				temp=temp+(aa.at(0)+1);

		    	cout<<"$ "<<temp<<endl;

		    	temp=temp+(aa.at(1)+2);

				//printf("%s\n",temp);
				if(check(temp)==0){
					q.push(temp);   cout<<"pushed1 : "<<temp<<endl;
				}	
		    }

		    //printf("$$ %s , %c\n",aa, aa[1] );

			if(aa.at(1)-2>='1'){
				string temp;
				temp=temp+(aa.at(0)+1);
				temp=temp+(aa.at(1)-2);

				//printf("%s\n",temp);
				if(check(temp)==0){	
					q.push(temp);    cout<<"pushed2 : "<<temp<<endl;
				 }	
			}
		}

	if(aa.at(0)+2 <='h'){
		
		if(aa.at(1)+1<='8'){
			string temp;
			temp=temp+(aa.at(0)+2);
			temp=temp+(aa.at(1)+1);

			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   cout<<"pushed3 : "<<temp<<endl;
			}
		
		}

		if(aa.at(1)-1>='1'){
			string temp;
			temp=temp+(aa.at(0)+2);
			temp=temp+(aa.at(1)-1);

			//printf("%s\n",temp);
			if(check(temp)==0){			
				q.push(temp);   cout<<"pushed4 : "<<temp<<endl;
			}

		}
	}

	if(aa.at(0)-2 >='a'){
		
		if(aa.at(1)+1<='8'){
			string temp;
			temp=temp+(aa.at(0)-2);
			temp=temp+(aa.at(1)+1);

			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   cout<<"pushed5 : "<<temp<<endl;
			}
		
		}

		if(aa.at(1)-1>='1'){
			string temp;
			temp=temp+(aa.at(0)-2);
			temp=temp+(aa.at(1)-1);

			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   cout<<"pushed6 : "<<temp<<endl;
			}

		}
	}

	if(aa.at(0)-1 >='a'){
		
		if(aa.at(1)+2<='8'){	
			string temp;
			temp=temp+(aa.at(0)-1);
			temp=temp+(aa.at(1)+2);

			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   cout<<"pushed7 : "<<temp<<endl;
			}
		
		}

		if(aa.at(1)-2>='1'){
			string temp;
			temp=temp+(aa.at(0)-1);
			temp=temp+(aa.at(1)-2);

			//printf("%s\n",temp);
			if(check(temp)==0){
				q.push(temp);   cout<<"pushed8 : "<<temp<<endl;
			}

		}

	}

	steps++;

   }	 //while ends

}*/

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

		cin>>a>>b;
		//bfs(a,b,0);

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