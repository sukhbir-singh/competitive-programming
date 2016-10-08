#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	
	int n;
	scanf("%d",&n);

	while(n!=0){
		long long sum=0;

		for(int i=1;i<=n;i++){
			sum+=i*i;
		}

		printf("%lld\n",sum );

		scanf("%d",&n);
	}

	return 0;
}