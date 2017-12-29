#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m,k;
    cin>>n>>k;

    lg left=60*4-k;

    if(left<0){
    	cout<<0;
    }else{
    	lg ans=0;
	    fr(i,1,n+1){
	    	if(left-5*i>=0){
	    		ans=i;
	    		left=left-5*i;
	    	}else{
	    		break;
	    	}
	    }    	

	    cout<<ans;
    }


    return 0;
}

