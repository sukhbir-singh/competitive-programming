#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n=2;
	string str;

	cin>>n;

	while(n!=0){
		cin>>str;

		//cout<<str<<endl;

		int len=str.length();

		int rows=len/n;

		int i=0;
		int j=0;

		int time=1;

		for(i=0;i<n;i++){
			int num1=2*(n-1-i)+1;
			int num2=2*n-num1;

			//printf("for i= %d, num1 = %d , num2 = %d \n",i,num1,num2 );

			time=1;

			for(j=i;j<len;){
				//printf("[%d , %d] ",i,j);

				cout<<str[j]<<"";

				if(time==1){
					j+=num1;
					time=2;
				}else{
					time=1;
					j+=num2;
				}

			}
		}

		cout<<endl;

		cin>>n;
	}


	return 0;
}