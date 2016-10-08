#include <bits/stdc++.h>
using namespace std;

int main()
{
	typedef long long lg;
	lg times,i,j,n;

	scanf("%lld",&times);
	
	for(i=0;i<times;i++){
		scanf("%lld",&n);
		
		lg num=1;

		map<string,long long> values;
		values["1"]=1%n;

		queue<string> q;
		q.push("1");

		string temp,temp1,temp2;
		string flag="";

		while(!q.empty()){

			temp=q.front();
			q.pop();

			if(values[temp]%n==0){
				flag=temp;
				break;
			}

			temp1=temp+"0";
			temp2=temp+"1";

			q.push(temp1);
			q.push(temp2);

			values[temp1]=values[temp]*(10%n);

			if(values[temp1]%n==0){
				flag=temp1;
				break;
			}

			values[temp2]=values[temp1] + (1%n);

			if(values[temp2]%n==0){
				flag=temp2;
				break;
			}

		}

		cout<<flag<<endl;

	}

	return 0;
}
