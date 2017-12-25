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

    fr(i,0,t){
    	cin>>n;
    	map<string,lg> mp;

    	fr(j,0,n){
    		string s;
    		cin>>s;

    		mp[s]=mp[s]+1;
    	}

    	string s1;
    	lg max=0;

    	for(auto it = mp.cbegin(); it != mp.cend(); ++it ){
    		if(it->second > max){
    			max=it->second;
    			s1=it->first;
    		}
    	}

    	string s2;
    	lg max1=0;

    	for(auto it = mp.cbegin(); it != mp.cend(); ++it ){
    		if(it->second > max1 && it->first != s1){
    			max1=it->second;
    			s2=it->first;
    		}
    	}


    	if(max==max1){
    		cout<<"Draw"<<endl;
    	}else{
    		cout<<s1<<endl;
    	}
    }

    return 0;
}

