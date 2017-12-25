#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg a,b,c,d;
    cin>>a>>b>>c>>d;
    lg x=a,y=b,z=c;

    int flag=0;

    fr(i,c,b){	
    	fr(j,b,a){
    		if(i>=d && i<=2*c && i<=2*d && 2*d<j && j<=2*b){
    			flag=1;
    			cout<<x<<endl<<j<<endl<<i;
    			break;
    		}
    	}
    	if(flag==1)
    		break;
    }

    if(flag==0){
    	cout<<"-1";
    }

    return 0;
}

