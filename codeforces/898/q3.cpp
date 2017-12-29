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

        if(mp.count(s)==1){
            st=mp[s];
        }

    	string temp;
    	fr(j,0,n){
    		cin>>temp;
    		st.insert(temp);
    	}

    	mp[s]=st;
    }

    cout<<mp.size()<<endl;

    for(auto it = mp.cbegin(); it != mp.cend(); ++it ){
        cout<<it->first <<" ";

        set<string> st=it->second;

        cout<<st.size()<<" ";

        auto it1=st.begin();
        while(it1!=st.end()){
            cout<<*it1<<" ";
            it1++;
        }

        cout<<endl;
    }

    return 0;
}

