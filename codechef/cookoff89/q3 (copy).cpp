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

    	lg ans=LONG_LONG_MAX;
    	lg current_sum=arr[0];
    	lg max_sum=arr[0];

    	if(max_sum>=d){
    		ans=1;
    	}

    	lg current_count=1;

    	fr(j,1,n){
    		lg temp=current_sum;
    		current_sum=max(current_sum,current_sum+arr[j]);
    		
    		if(current_sum!=temp){
    			current_count++;
    		}else{
    			current_count=1;
    		}

    		if(arr[j]==0){
    			current_count++;
    		}

    		cout<<"current sum: "<<current_sum<<" , "<<current_count<<endl;

			if(current_sum>=d){
				ans=min(ans,current_count);
			}    		

    		max_sum=max(max_sum,current_sum);
       	}

    	if(ans==LONG_LONG_MAX){
    		cout<<-1<<endl;
    	}else{
    		cout<<ans<<endl;
    	}
    }

    return 0;
}

