#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;
int add(int x,int y){int res=(x+0LL+y)%MOD;return (res<0)?res+MOD:res;}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m,k,count=0;
    cin>>n>>k;
    lg arr[k];

    map<lg,lg> mp;

    fr(i,0,k){
    	cin>>arr[i];
    	mp[arr[i]]=1;
    }

    lg index=1;

    fr(i,0,k){
		cout<<arr[i]<<" ";

    	fr(j,1,n){
    		while(mp[index]==1){
				index++;
			}    		
			cout<<index<<" ";
			index++;
    	}
    	cout<<endl;
    }

    return 0;
}

