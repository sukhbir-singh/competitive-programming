#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
#define NINF LONG_MIN
typedef long long lg;
typedef pair<lg,lg> pii;
int add(int x,int y){int res=(x+0LL+y)%MOD;return (res<0)?res+MOD:res;}

string a,b;
lg dp[5003][5003];

lg run(lg p,lg q){
	if(dp[p][q]!=-1){
		return dp[p][q];
	}

	if(p==0){
		dp[p][q]=q;
		return q;
	}
	if(q==0){
		dp[p][q]=p;
		return p;
	}

	lg ans=0;

	if(a[p-1]==b[q-1]){
		ans=run(p-1,q-1)+1;
	}else{
		ans=1+min(run(p,q-1), run(p-1,q));
	}

	dp[p][q]=ans;
	return ans;
}

string prcess(string str){
	lg len=str.length();
	string s="";

	char prev='-';
	fr(i,0,len){		
		if(str[i]!=prev){
			s+=str[i];			
		}
		prev=str[i];
	}

	return s;
}

int main(){
	ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>t;

    fr(i,0,t){
    	cin>>n>>m;
    	cin>>a>>b;

    	a=prcess(a);
    	b=prcess(b);

    	lg l1=a.length(),l2=b.length();

    	memset(dp,-1,sizeof dp);

    	cout<<run(l1,l2)<<endl;
    }

    return 0;
}

