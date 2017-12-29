#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,a,b,n,m;
    cin>>n>>a>>b;

    lg a1=0,a2=0;
    int flag=0;

    fr(i,0,n){
    	if(i*a>n){
    		flag=0;
    		break;
    	}

    	if((n-a*i)%b==0){
    		a1=i; a2=(n-a*i)/b;
    		flag=1;
    		break;
    	}
    }

    if(flag==0){
    	cout<<"NO";
    }else{
		cout<<"YES\n";
		cout<<a1<<" "<<a2<<endl;
    }

    return 0;
}

