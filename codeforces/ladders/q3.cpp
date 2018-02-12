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
    lg t,n,m;
    cin>>n>>m;

    string s[n];
    lg h[m];   
    memset(h,0,sizeof h);

    fr(i,0,n){
    	cin>>s[i];
    	fr(j,0,m){
    		if(s[i][j]-'0'>h[j]){
    			h[j]=s[i][j]-'0';
    		}
    	}
    }

    lg count=0;
    fr(i,0,n){
    	fr(j,0,m){
    		if(s[i][j]-'0'==h[j]){
    			count++;
    			break;
    		}
    	}
    }

    cout<<count;
    return 0;
}

