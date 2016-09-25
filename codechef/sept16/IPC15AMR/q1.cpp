#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	typedef long long lg;
	lg n,m;

	scanf("%lld%lld",&n,&m);

	int a[n][26],b[m][26];

	for(lg i=0;i<n;i++){
		for(lg j=0;j<26;j++){
			a[i][j]=0;
		}

	}

	for(lg i=0;i<m;i++){
		for(lg j=0;j<26;j++){
			b[i][j]=0;
		}
	}

	string t;

	for(lg i=0;i<n;i++){

		cin>>t;
		int l=t.length();

		for(lg j=0;j<l;j++){
			int d=t[j]-'A';

			a[i][d]=1;
		}

	}

	for(lg i=0;i<m;i++){

		cin>>t;
		int l=t.length();

		for(lg j=0;j<l;j++){
			int d=t[j]-'A';

			b[i][d]=1;
		}
		
	}

	/*for(lg i=0;i<n;i++){
		for(lg j=0;j<26;j++){
			printf("%d ",a[i][j]);
		}

		printf("\n");
	}

	printf("\n\n");

	for(lg i=0;i<m;i++){
		for(lg j=0;j<26;j++){
			printf("%d ",b[i][j]);
		}

		printf("\n");
	}*/

	lg count=0;

	for(lg i=0;i<n;i++){

		for(lg k=0;k<m;k++){
			int flag=0;

			for(lg j=0;j<26;j++){
				
				if(a[i][j]+b[k][j]==0){
					flag=1;
					break;
				}
			}

			if(flag==0){
				count++;
			}

		}
	}

	printf("%lld\n",count );
}