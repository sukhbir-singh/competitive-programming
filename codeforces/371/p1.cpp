#include <bits/stdc++.h>

int main()
{
	typedef long long lg;
	lg times,i,j;
	
		lg l1,r1,l2,r2,k;
		scanf("%I64d%I64d%I64d%I64d%I64d",&l1,&r1,&l2,&r2,&k);

		lg time=0;

		lg lower=l1,upper=r1;

		if(l2>=l1){
			lower=l2;
		}	

		if(r2<r1){
			upper=r2;
		}

		time=upper-lower+1;

		if(k>=lower && k<=upper){
			time--;
		}

		int flag=0;

		if(l2>r1 || r2<l1){
			flag=1;
		}

		if(flag==1){
			printf("0\n");
		}else{
			printf("%I64d\n",time);

		}

		return 0;
}