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

int main(){
    lg t,n,q,m,x,y;
    cin>>t;
    lg arr[t];

    fr(i,0,t){
    	cin>>arr[i];
    }

    lg monsters=t;
    int bits=3;

    vector<int> sets[bits];

    fr(i,0,t){
    	rfr(j,bits-1,0){
    		if((i&(1<<j))==0){
    			sets[j].push_back(i);
    		}
	    }
    }
    
    // fr(i,0,bits){
    // 	cout<<"vector "<<i<<" : ";
    // 	fr(j,0,sets[i].size()){
    // 		cout<<sets[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }
    // cout<<endl;

    cin>>q;
    while(q--){
    	cin>>x>>y;
		
		vector<int> final;
		int start=-1;

    	rfr(i,bits-1,0){
    		if((x&(1<<i))==0){
    			if(start==-1){
    				final=sets[i];
    				start=1;
    			}else{
    				// cout<<"combining\nset1: ";
    				// fr(k,0,final.size()){
    				// 	cout<<final[k]<<" ";
    				// }
    				// cout<<endl<<"set2: ";
    				// fr(k,0,sets[i].size()){
    				// 	cout<<sets[i][k]<<" ";
    				// }
    				// cout<<endl;

    				vector<int> v3;
    				set_intersection(final.begin(),final.end(),sets[i].begin(),sets[i].end(), std::back_inserter(v3));
    				final=v3;

    				// cout<<"result set: ";
    				// fr(k,0,final.size()){
    				// 	cout<<final[k]<<" ";
    				// }
    				// cout<<endl;
    			}
    		}
    	}

    	int len=final.size();

    	// cout<<"final elements: ";
    	fr(i,0,len){
    		int index=final[i];
    		// cout<<index<<" ";

    		if(arr[index]>0){
    			arr[index]-=y;

    			if(arr[index]<=0){
    				monsters--;
    			}
    		}
    	}

		cout<<monsters<<endl;
    }
}

