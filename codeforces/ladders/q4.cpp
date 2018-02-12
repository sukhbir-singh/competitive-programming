#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;
int add(int x,int y){int res=(x+0LL+y)%MOD;return (res<0)?res+MOD:res;}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>t;
    string s,s1="";
    cin>>s;

    map<char,lg> mp;
    fr(i,0,s.length()){
    	if(mp[s[i]]==0){
    		s1=s1+s[i];
    	}
    	mp[s[i]]=mp[s[i]]+1;
    }

    int flag=1;
    fr(i,0,s1.length()){
    	if(mp[s1[i]]%t!=0){
    		flag=0;
    		break;
    	}
    }

    if(flag==0){
    	cout<<-1;
    }else{
    	fr(i,0,t){
    		fr(j,0,s1.length()){
    			fr(p,0,mp[s1[j]]/t){
    				cout<<s1[j];
    			}
    		}    		
    	}
    }

    return 0;
}

