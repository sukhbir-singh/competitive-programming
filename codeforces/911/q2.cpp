#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m,a,b;
    cin>>n>>a>>b;
    lg a1=a,a2=b;

    if(n==a+b){
    	cout<<1<<endl;
    	return 0;
    }else{
    	lg mx=0;
    	fr(b1,1,n){
    		lg left=b1;
    		lg right=n-b1;

    		lg temp;
    		// if(left!=0 && right!=0){
    		temp=min(a/left,b/right);
    			
    		// }else{
    		// 	if(left==0){
    		// 		temp=b/right;
    		// 	}else{
    		// 		temp=a/left;
    		// 	}	
    		// }
    		if(temp>mx){
    			mx=temp;
    		}
    	}

    	cout<<mx<<endl;
    }

    return 0;
}

