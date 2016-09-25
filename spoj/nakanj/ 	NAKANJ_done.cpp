#include<bits/stdc++.h>
using namespace std;

int arr[8][8];
int level[8][8];

/*void visit(string a){
	//cout<<"visited "<<a<<endl;
	arr[a[0]-'a'][a[1]-'1']=1;
}*/

/*int check(string a){
	return arr[a[0]-'a'][a[1]-'1'];
}*/

void bfs(string a,string b){
	// d4    e2 e6 f5 f3 c2 c6 b3 b5
	queue<string> q;
	q.push(a);
	level[a[0]-'a'][a[1]-'1']=0;
	arr[a[0]-'a'][a[1]-'1']=1;

	int count=0;

	while(!q.empty()){
	count++;  
		string aa=q.front(); 
		int temp_level=level[aa[0]-'a'][aa[1]-'1'];

		char aa0=aa[0];
		char aa1=aa[1];

		q.pop();
		
		if(aa0==b[0] && aa1==b[1]){
			cout<<temp_level<<"\n";
			break;
		}

		if(aa0+1 <='h'){		
			if(aa1+2<='8'){

				string temp;
				temp=aa0+1;
		    	temp+=(aa1+2);

				if(arr[temp[0]-'a'][temp[1]-'1']==0){
					q.push(temp);   //cout<<"pushed1 : "<<temp<<endl;
					arr[temp[0]-'a'][temp[1]-'1']=1;
					level[temp[0]-'a'][temp[1]-'1']=temp_level+1;
				}	
		    }

			if(aa1-2>='1'){
				string temp;
				temp=(aa0+1);
				temp+=(aa1-2);

				if(arr[temp[0]-'a'][temp[1]-'1']==0){	
					q.push(temp);    //cout<<"pushed2 : "<<temp<<endl;
					arr[temp[0]-'a'][temp[1]-'1']=1;
					level[temp[0]-'a'][temp[1]-'1']=temp_level+1;
				 }	
			}
		}

	if(aa0+2 <='h'){
		
		if(aa1+1<='8'){
			string temp;
			temp=(aa0+2);
			temp+=(aa1+1);

			if(arr[temp[0]-'a'][temp[1]-'1']==0){
				q.push(temp);   //cout<<"pushed3 : "<<temp<<endl;
				arr[temp[0]-'a'][temp[1]-'1']=1;
				level[temp[0]-'a'][temp[1]-'1']=temp_level+1;
			}
		
		}

		if(aa1-1>='1'){
			string temp;
			temp=(aa0+2);
			temp+=(aa1-1);

			if(arr[temp[0]-'a'][temp[1]-'1']==0){			
				q.push(temp);   //cout<<"pushed4 : "<<temp<<endl;
				arr[temp[0]-'a'][temp[1]-'1']=1;
				level[temp[0]-'a'][temp[1]-'1']=temp_level+1;
			}

		}
	}

	if(aa0-2 >='a'){
		
		if(aa1+1<='8'){
			string temp;
			temp=(aa0-2);
			temp+=(aa1+1);

			if(arr[temp[0]-'a'][temp[1]-'1']==0){
				q.push(temp);   //cout<<"pushed5 : "<<temp<<endl;
				arr[temp[0]-'a'][temp[1]-'1']=1;
				level[temp[0]-'a'][temp[1]-'1']=temp_level+1;
			}
		
		}

		if(aa1-1>='1'){
			string temp;
			temp=(aa0-2);
			temp+=(aa1-1);

			if(arr[temp[0]-'a'][temp[1]-'1']==0){
				q.push(temp);   //cout<<"pushed6 : "<<temp<<endl;
				arr[temp[0]-'a'][temp[1]-'1']=1;
				level[temp[0]-'a'][temp[1]-'1']=temp_level+1;
			}

		}
	}

	if(aa0-1 >='a'){
		
		if(aa1+2<='8'){	
			string temp;
			temp=(aa0-1);
			temp+=(aa1+2);

			if(arr[temp[0]-'a'][temp[1]-'1']==0){
				q.push(temp);   //cout<<"pushed7 : "<<temp<<endl;
				arr[temp[0]-'a'][temp[1]-'1']=1;
				level[temp[0]-'a'][temp[1]-'1']=temp_level+1;
			}
		
		}

		if(aa1-2>='1'){
			string temp;
			temp=(aa0-1);
			temp+=(aa1-2);

			if(arr[temp[0]-'a'][temp[1]-'1']==0){
				q.push(temp);   //cout<<"pushed8 : "<<temp<<endl;

				arr[temp[0]-'a'][temp[1]-'1']=1;
				level[temp[0]-'a'][temp[1]-'1']=temp_level+1;
			}

		}

	}

   }	 //while ends

   //cout<<"#"<<count<<"\n";

}

int main(){
	std::ios::sync_with_stdio(false);

	int times;
	cin>>times;

	string a,b;

	for(int i=0;i<times;i++){

		
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				arr[j][k]=0;
				level[j][k] = 0;
			}
		}

		cin>>a>>b;
		bfs(a,b);
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