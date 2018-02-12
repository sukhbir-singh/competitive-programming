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
    lg t,n,m;
    srand(time(NULL)); 
    cin>>n;

    lg b[n],e[n];

    fr(i,0,n){
    	cin>>e[i];
    }

    fr(i,0,n){
    	cin>>b[i];
    }
	
	fr(i,0,n){
		int r=rand();
		int index=r%e[i]; 

		string s="";

		fr(j,0,e[i]){
	    	s+="w";
	    }

	    fr(j,0,b[i]){
	    	s[(index+j)%e[i]]='b';
	    }

    	cout<<s<<endl;	
	}

	vector<lg> arr;
	fr(i,1,n+1){
		arr.push_back(i);
	}

	random_shuffle(arr.begin(),arr.end());

	fr(i,0,n){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

    return 0;
}

