#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rfr(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
typedef long long lg;

bool sum_n(lg k,lg n){
	lg sum=0;

	while(1){
		sum+=k%10;
		k=k/10;

		if(k==0){
			break;
		}
	}

	if(sum==n){
		return true;
	}else{
		return false;
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>t;

    fr(i,0,t){
    	cin>>n;

    	lg k=n;
    	while(!sum_n(k,n)){
    		k+=n;
    	}

    	cout<<k<<endl;
    }

    return 0;
}

