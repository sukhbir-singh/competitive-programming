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
    ios_base::sync_with_stdio(false); 
    lg t,n,m,k;
    cin>>t;

    fr(i,0,t){
    	cin>>n>>k;
		lg arr[n];

        lg s=0;
        // lg ms=0; 
        lg lm=0;
        lg rm=0;

    	fr(i,0,n){
    		cin>>arr[i];
    		s+=arr[i];
    	}

        lg curr=arr[0];
        lg ms=arr[0];
 
        fr(i,1,n){
            curr=max(arr[i], curr+arr[i]);
            ms=max(ms,curr);
        }

        lm=arr[0];
        rm=arr[n-1];

        lg temp=lm;       
        fr(i,1,n){
            if(i>=n) break;
            temp+=arr[i];
            lm=max(temp,lm);
        }
 
        temp=rm;
        rfr(i,n-2,0){
            if(i<0) break;
            temp+=arr[i];
            rm=max(temp,rm);
        }

        // s ms lm rm
        lg s_backup=s,ms_backup=ms,lm_backup=lm,rm_backup=rm;
        
        fr(i,1,k){
            s=s+s_backup;
            ms=max(max(ms,ms_backup), rm+lm_backup);
            lm=max(lm, s+lm_backup);
            rm=max(rm_backup, s_backup+rm);
        }
        
        cout<<ms<<endl;

    }

    return 0;
}

