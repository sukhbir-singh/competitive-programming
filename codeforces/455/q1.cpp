#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    // ios_base::sync_with_stdio(false); 
    lg t,n,m;
    string s1,s2;
    // cin>>s1;

    getline(cin,s1);

    lg l1=s1.length();//l2=s2.length();
    lg tt=0;
    fr(i,0,s1.length()){
    	if(s1[i]==' '){
    		tt=i;
    	}
    }

    tt++;

    lg a1=1,a2=0;
    string ans="";
    ans=ans+s1[0];

    while(a1<tt-1){
    	if(s1[a1]<s1[tt]){
    		ans=ans+s1[a1];
    	}else{
    		break;
    	}
    	a1++;
    }

    ans=ans+s1[tt];
	
    cout<<ans<<endl;

    return 0;
}

