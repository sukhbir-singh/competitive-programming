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
    lg a[4];
    lg t;
    cin>>t;

    while(t--){
    	fr(i,0,4){
	    	cin>>a[i];
	    }
	    sort(a,a+4);

	    if((a[0]==a[1])&&(a[2]==a[3])){
	    	cout<<"YES\n";
	    }else{
	    	cout<<"NO\n";
	    }
    }

    return 0;
}

