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

		queue<long long> q;
		q.push(1);

		lg temp,temp1,temp2;
		lg flag=0;

		while(!q.empty()){

			temp=q.front();
			q.pop();

			if(temp%n==0){
				flag=temp;
				break;
			}

			temp1=temp*10;
			temp2=temp*10+1;

			q.push(temp1);
			q.push(temp2);

		}

		printf("%lld\n",flag );

	}

	return 0;
}
