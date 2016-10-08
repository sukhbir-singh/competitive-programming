#include <bits/stdc++.h>
long long power(int x, unsigned int y){
    long long temp;
    if(y==0)return 1;
    temp = power(x, y/2);
    if(y%2== 0)return temp*temp;
    else return x*temp*temp;
}

int main(int argc, char const *argv[])
{
	typedef long long lg;
	lg i,j,a,b,times;

	scanf("%lld",&times);

	for(i=0;i<times;i++){
		scanf("%lld%lld",&a,&b);

		lg temp=a,index=0;

		if(b%4==0){
			index=4;
		}else{
			index=b%4;
		}

		temp=power(a%10,index);

		if(b==0){
			printf("1\n");
		}else{
			printf("%lld\n",temp%10 );
		}
	}
	return 0;
}