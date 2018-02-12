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
    lg t,n,m,r,k;
    cin>>n>>m>>r>>k;

    lg fours=(n-2)*(m-2);
    lg twos=2*(m-2)+2*(n-2);
    lg ones=4;

    lg sqrs=(n-r+1)*(m-r+1);

    lg rem=k;
    lg sum=0;

    if(k<=fours){
    	sum+=k*4;
    }else if(k<=(fours+twos)){
    	sum+=fours*4 + (k-fours)*2;
    }else{
    	sum+=fours*4 + (fours+twos)*2 +(k-fours-twos)*1;
    }

    double ans=1.0*(sum)/sqrs;

    printf("%.16lf\n", ans);

    return 0;
}

