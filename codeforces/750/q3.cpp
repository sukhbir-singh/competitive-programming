#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
#define NINF LONG_MIN
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>t;

    lg change[t],level[t];
    int flag=1;
    lg l1=-1,l2=-1;

    fr(i,0,t){
    	cin>>change[i]>>level[i];
    }

    lg from=NINF,to=INF;
    bool p1=true,p2=false;

    fr(i,0,t){
    	if(level[i]==1){
    		lg temp=1900;
    		from=max(temp,from);
    	}else{
    		lg temp=1899;
    		to=min(temp,to);
    	}

    	if(from!=INF && from!=NINF){
    		from+=change[i];
    	}
    	if(to!=INF && to!=NINF){
    		to+=change[i];
    	}
    }

    if(from>to){
    	cout<<"Impossible";
    }else{
    	if(from==INF || to==INF){
    		cout<<"Infinity";
    	}else{
    		cout<<to;
    	}
    }

    return 0;
}

