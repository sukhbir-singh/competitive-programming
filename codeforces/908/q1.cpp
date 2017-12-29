#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n=0,m;

    string s;
    cin>>s;

    t=s.length();

    fr(i,0,t){
    	if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u')){
    		n++;
    	}else if((s[i]=='1')||(s[i]=='3')||(s[i]=='5')||(s[i]=='7')||(s[i]=='9')){
    		n++;
    	}
    }

    cout<<n;

    return 0;
}

