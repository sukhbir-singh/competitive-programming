#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;
#define MOD 1000000007

lg dp[5005][5005];

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>n;
    string arr[n],s;

    fr(i,0,n){
    	cin>>arr[i];
    }

	dp[0][0]=1;

	fr(i,1,n){
		if(arr[i-1]=="f"){
			fr(j,0,n){
				if(j==0){
					dp[i][j]=0;
				}else{
					dp[i][j]=dp[i-1][j-1];
				}	
			}
		}else{
			lg sum=0;
			rfr(j,n-1,0){
				sum+=dp[i-1][j]%MOD;
				dp[i][j]=sum;
			}
			
		}
	}

	lg ans=0;
	fr(i,0,n){
		ans+=dp[n-1][i]%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;

    return 0;
}

