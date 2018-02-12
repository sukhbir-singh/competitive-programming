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
    lg t,n,m,a,b,x,y,z;
    cin>>a>>b>>x>>y>>z;

    lg sum=a+b;
    lg yy=2*x+y;
    lg bb=y+3*z;

    if(a>=yy && b>=bb){
    	cout<<0<<endl;
    }else{
    	lg cc=0;
    	if(yy>a){
    		cc+=yy-a;
    	}
    	if(bb>b){
    		cc+=bb-b;
    	}
    	cout<<cc<<endl;
    }

    return 0;
}

