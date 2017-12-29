#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>t;

    if(t%10==0){
    	cout<<t<<endl;
    }else{
    	if(t%10<=5){
    		t=t-t%10;
    	}else{
    		t=t-t%10+10;
    	}
    	cout<<t<<endl;
    }

    return 0;
}

