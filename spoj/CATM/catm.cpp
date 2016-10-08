#include <bits/stdc++.h>
using namespace std;

int main()
{
	typedef long long lg;
	lg n,m,times,i,j;
	lg mx,my,c1x,c1y,c2x,c2y;

	scanf("%lld%lld",&m,&n);

	scanf("%lld",&times);
	
	for(i=0;i<times;i++){
		scanf("%lld%lld%lld%lld%lld%lld",&mx,&my,&c1x,&c1y,&c2x,&c2y);

		int arr1[m],arr2[m],arr3[n],arr4[n];
	
		// arr1 arr2
		for(j=1;j<=m;j++){
			
			int temp=(c1y-0);

			if(c1x>=j){
				temp+=c1x-j;
			}else{
				temp+=j-c1x;
			}

			int temp2=(c2y-0);

			if(c2x>=j){
				temp2+=c2x-j;
			}else{
				temp2+=j-c2x;
			}

			if(temp<=temp2){
				arr1[j-1]=temp;
			}else{
				arr1[j-1]=temp2;
			}
			

			//

			int temp1=n+1-c1y;

			if(c1x>=j){
				temp1+=c1x-j;
			}else{
				temp1+=j-c1x;
			}

			int temp3=n+1-c2y;

			if(c2x>=j){
				temp3+=c2x-j;
			}else{
				temp3+=j-c2x;
			}

			if(temp1<=temp3){
				arr2[j-1]=temp1;
			}else{
				arr2[j-1]=temp3;
			}

		}

		// arr3 arr4
		for(j=1;j<=n;j++){
			
			int temp=(c1x-0);

			if(c1y>=j){
				temp+=c1y-j;
			}else{
				temp+=j-c1y;
			}

			int temp2=(c2x-0);

			if(c2y>=j){
				temp2+=c2y-j;
			}else{
				temp2+=j-c2y;
			}

			if(temp<=temp2){
				arr3[j-1]=temp;
			}else{
				arr3[j-1]=temp2;
			}
			

			//

			int temp1=m+1-c1x;

			if(c1y>=j){
				temp1+=c1y-j;
			}else{
				temp1+=j-c1y;
			}

			int temp3=m+1-c2x;

			if(c2y>=j){
				temp3+=c2y-j;
			}else{
				temp3+=j-c2y;
			}

			if(temp1<=temp3){
				arr4[j-1]=temp1;
			}else{
				arr4[j-1]=temp3;
			}

		}

		// values print

		/*printf("arr1: ");

		for(j=0;j<m;j++){
			printf("%d ",arr1[j] );
		}

		printf("\narr2: ");

		for(j=0;j<m;j++){
			printf("%d ",arr2[j] );
		}

		printf("\narr3: ");

		for(j=0;j<n;j++){
			printf("%d ",arr3[j] );
		}

		printf("\narr4: ");

		for(j=0;j<n;j++){
			printf("%d ",arr4[j] );
		}

		printf("\n");*/

		int flag=0;

		// now we have calculated distances for cats now for mouse
		// arr1 arr2
		for(j=1;j<=m;j++){
			
			int temp=(my-0);

			if(mx>=j){
				temp+=mx-j;
			}else{
				temp+=j-mx;
			}

			if(temp<arr1[j-1]){
				flag=1;
				break;
			}

			temp=(n+1-my);

			if(mx>=j){
				temp+=mx-j;
			}else{
				temp+=j-mx;
			}

			if(temp<arr2[j-1]){
				flag=1;
				break;
			}

		}

		for(j=1;j<=n;j++){
			
			int temp=(mx-0);

			if(my>=j){
				temp+=my-j;
			}else{
				temp+=j-my;
			}

			if(temp<arr3[j-1]){
				flag=1;
				break;
			}

			temp=(m+1-mx);

			if(my>=j){
				temp+=my-j;
			}else{
				temp+=j-my;
			}

			if(temp<arr4[j-1]){
				flag=1;
				break;
			}

		}

		if(flag==1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	
	}

	return 0;
}
