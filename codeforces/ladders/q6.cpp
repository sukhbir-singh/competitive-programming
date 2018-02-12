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
    lg t,n,m,a1,a2;
    cin>>t;
    lg c1=0,c2=0,c3=0;

    fr(i,0,t){
    	cin>>a1>>a2;
    	if(a1%2==1 && a2%2==0){
    		c1++;
    	}else if(a1%2==0 && a2%2==1){
    		c2++;
    	}else if(a2%2==1 && a1%2==1){
    		c3++;
    	}
    }

    lg ans=0;
    lg m1=c1%2,m2=c2%2,m3=c3%2;
    // cout<<"C: "<<c1<<" "<<c2<<" "<<c3<<endl;
    // cout<<"M: "<<m1<<" "<<m2<<" "<<m3<<endl;

    if(m1==0 && m2==0 && m3==0){
    	ans=0;
    }else if(m3==1){
    	if(m1==1 && m2==1){
    		ans=0;
    	}else if(m1==0 && m2==0 && (c1>0||c2>0)){ 
    		// important point
    		ans=1;
    	}else if(m1==0 && m2==0 && (c1==0 && c2==0)){ 
    		ans=-1;
    	}else if(m1==1 && m2==0){
    		ans=-1;
    	}else if(m1==0 && m2==1){
    		ans=-1;
    	}
    }else{ // m3==0
    	if(m1==1 && m2==1){
    		ans=1;
    	}else{
    		ans=-1;
    	}
    }

    cout<<ans;

    return 0;
}

