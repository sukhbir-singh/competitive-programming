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
    	lg arr[n];
    	lg sum=0;
    	lg count=0;

    	fr(j,0,n){
    		cin>>arr[j];
    		if(arr[j]%4!=0){
    			sum+=arr[j];
    			count++;
    		}
    	}

    	if(sum%4==0){
    		cout<<(count+1)/2<<endl;
    	}else{
    		cout<<"-1\n";
    	}

    }

    return 0;
}

