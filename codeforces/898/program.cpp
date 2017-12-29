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
    string s;
    map<string,set<string>> mp;

    fr(i,0,t){
    	cin>>s;
    	cin>>n;

    	set<string> st;
    	string temp;
    	fr(j,0,n){
    		cin>>temp;
    		st.insert(temp);
    	}

    	mp[s]=st;
    }

    return 0;
}

