#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

lg n;

int main(){
	ios_base::sync_with_stdio(false); 
    lg d,k;
    cin>>d;

    fr(i,0,d){
    	cin>>n>>k;
    	lg arr[2*n+1];
    	memset(arr,0,sizeof(arr));

    	lg t;
    	fr(j,0,k){
    		cin>>t;
    		arr[t]=1;
    	}

    	lg dp[2*n+1][2*n+1];
    	memset(dp,0,sizeof(dp));

    	fr(j,0,2*n+1){
    		fr(k,0,2*n+1){

    			if(j==0){
    				dp[j][k]=0;
    			}else if(j==1 && k==1){
    				dp[j][k]=1;
    			}else if(j==1 && k>1){
    				dp[j][k]=0;
    			}else{
    				if(arr[j]==1){
    					if(k==0){
    						dp[j][k]=0;
    					}else{
    						dp[j][k]=dp[j-1][k-1];
    					}
    				}else{
    					if(k==0){
    						dp[j][k]=dp[j-1][1];
    					}else{
    						dp[j][k]=dp[j-1][k-1]+dp[j-1][k+1];
    					}
    				}
    			}

    			if(j==2*n && k==0){
    				break;
    			}
    		}
    	}

    	cout<<dp[2*n][0]<<endl;
    }

    return 0;
}

