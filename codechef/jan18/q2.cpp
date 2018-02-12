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
    lg arr[705][705];

    fr(i,0,t){
    	cin>>n;

    	fr(j,0,n){
    		fr(k,0,n){
    			cin>>arr[j][k];
    		}
    	}

    	lg max=-1,sum=0;

    	bool flag=true;

    	rfr(j,n-1,0){
    		flag=true;
    		lg bf=max;
    		max=-1;

    		fr(k,0,n){    			
    			if(j==n-1){
    				if(arr[j][k]>max){
	    				max=arr[j][k];
	    			}	
    			}else{
    				if(arr[j][k]>max && arr[j][k]<bf){
	    				max=arr[j][k];
	    			}
    			}
    		}

    		if(max==-1){
    			flag=false;
    			break;
    		}

    		sum+=max;
    	}

    	if(flag){
    		cout<<sum<<endl;
    	}else{
    		cout<<-1<<endl;
    	}
    }

    return 0;
}

