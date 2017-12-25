#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m,d;
    cin>>t;

    fr(i,0,t){
    	cin>>n>>d;
    	lg arr[n];
    	fr(j,0,n){
    		cin>>arr[j];
    	}

    	lg ans=LONG_LONG_MAX, start=0, current_sum=0;

	    for(lg end=0; end<n; end++){
	        current_sum+=arr[end];
	        if(current_sum<=0){
	            start=end;
	            current_sum=0;
	        }
	        while(current_sum>=d && start<=end){
	            ans=min(ans, end-start+1);
	            current_sum-=arr[start];
	            start++;
	        }
	    }

	    if(ans!=LONG_LONG_MAX){
	    	cout<<ans<<endl;
	    }else{
	    	cout<<-1<<endl;
	    }
    }

    return 0;
}

