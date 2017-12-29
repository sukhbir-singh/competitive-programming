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
    string s;

    lg x=0,y=0;

    lg flag=1;

    fr(i,0,t){
    	cin>>n;
    	cin>>s;

    	if(n>(20000-y) && (s=="South")){
    		flag=0;
    		continue;
    	}else if(n>(y) && (s=="North")){
    		flag=0;
    		continue;
    	}

    	if(y==0 && s!="South"){
    		flag=0;
    	}else if(y==20000 && s!="North"){
    		flag=0;
    	}else{
    		if(s=="North"){
    			y=(y-n);
    		}else if(s=="South"){
    			y=y+n;
    		}
    	}
    }

    if(flag==0){
    	cout<<"NO";
    }else{
    	if(y==0){
    		cout<<"YES";
    	}else{
    		cout<<"NO";
    	}
    }

    return 0;
}

