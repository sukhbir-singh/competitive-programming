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
    lg t,n,m,k;
    cin>>n>>k;

    if(k==1){
    	cout<<n<<endl;
    }else{
    	lg temp=n;
    	lg sum=1;
    	while(n>=sum){
    		sum=sum<<1;
    	}
    	cout<<sum-1<<endl;
    }


    return 0;
}

