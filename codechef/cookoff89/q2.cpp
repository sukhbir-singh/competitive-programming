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

    	lg n1=0,n2=0,n3=0;

    	fr(j,0,n){
    		cin>>arr[j];
    		if(arr[j]%4!=0){
    			sum+=arr[j];
    			count++;

    			if(arr[j]%4==1){
    				n1++;
    			}else if(arr[j]%4==2){
    				n2++;
    			}else{
    				n3++;
    			}
    		}
    	}

    	if(sum%4==0){
    		// ans
    		ans=0;
    		ans+=n2/2;

    		if(n1>=n3){
    			ans+=(n1-n3);
    			
    		}else{
    			ans+=n3-n1;
    		}

    		if(n2%2==1){
    			if(n3)
    		}else{

    		}

    	}else{
    		cout<<"-1\n";
    	}

    }

    return 0;
}

