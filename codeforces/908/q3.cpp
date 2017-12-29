#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    lg t,n,m,r;
    cin>>n>>r;

    lg arr[n];
    fr(i,0,n){
    	cin>>arr[i];
    }

    vector<pair<lg,double>> v;

    fr(i,0,n){
    	if(i==0){
    		cout<<r<<" ";
    		v.push_back(mkp(arr[i],1.0*r));
    	}else{
    		lg x=arr[i];
    		double mx=0,tx=-1,ty=-1;

    		fr(j,0,v.size()){
    			if(abs(v[j].first-x)<=2*r){    			
    				if(v[j].second >= mx){
    					mx=v[j].second;

    					tx=v[j].first;
    					ty=v[j].second;
    				}
    			}
    		}

            if(tx==-1){
              cout<<r<<" ";
                v.push_back(mkp(arr[i],1.0*r));  
            }else{
                lg diff=abs(tx-x);
                double y=1.0*ty + sqrt(4*r*r-1.0*diff*diff)*1.0;
                
                printf("%.15f ",y);

                // cout<<y<<" ";
                v.push_back(make_pair(x,y));    
            }

    		
    	}
    }
    
    return 0;
}

