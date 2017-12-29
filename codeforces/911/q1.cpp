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
    lg t,n,m;
    cin>>t;
    lg arr[t];
    map<lg,lg > mp;
    lg mini=LONG_MAX;

    lg value=LONG_MAX;

    fr(i,0,t){
    	cin>>arr[i];
    	value=min(value,arr[i]);
    }

    fr(i,0,t){
    	if(arr[i]!=value){
    		continue;
    	}

    	if(mp.count(arr[i])){
    		if((i-mp[arr[i]])<mini){
    			mini=i-mp[arr[i]];
    		}
    		mp[arr[i]]=i;
    	}else{
    		mp[arr[i]]=i;
    	}
    }

	if(mini!=LONG_MAX)
    	cout<<mini<<endl;
	else
		cout<<0<<endl;

    return 0;
}

