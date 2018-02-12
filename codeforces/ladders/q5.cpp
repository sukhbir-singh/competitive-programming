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
    lg n,m,k;
    cin>>n>>k;
    lg p[n],t[n];
    lg dd[n];
    vector<pii> v;
    fr(i,0,n){
    	cin>>p[i]>>t[i];
    	v.push_back(mkp(p[i],-t[i]));
    }
    sort(v.begin(),v.end());
   	map<lg,lg> mp;
    lg last1=-1,last2=-1;
    lg index=0;

	rfr(i,n-1,0){
    	if(v[i].first!=last1 || v[i].second!=last2){
    		index++;
    	}
    	dd[i]=index;
    	mp[index]=mp[index]+1;
    	last1=v[i].first;
    	last2=v[i].second;
    }

    // rfr(i,n-1,0){
    // 	cout<<v[i].first<<" "<<v[i].second<<" , dd: "<<dd[i]<<endl;
    // }

    cout<<mp[dd[n-k]]<<endl;

    return 0;
}

