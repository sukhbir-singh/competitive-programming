#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;

int ff(string s){
	if(s=="mon"){return 0;}
	else if(s=="tues"){return 1;}
	else if(s=="wed"){return 2;}
	else if(s=="thurs"){return 3;}
	else if(s=="fri"){return 4;}
	else if(s=="sat"){return 5;} 
	else if(s=="sun"){return 6;} 
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>t;
    string s;

    fr(i,0,t){
    	cin>>n>>s;
    	int arr[7];
    	fr(j,0,7){
    		arr[j]=4;
    	}

    	{
    		int ll=ff(s);

    		int diff=n-28;

    		while(diff-->0){
    			arr[(ll+diff)%7]++;	
    		}
    		
    		fr(j,0,7){
	    		cout<<arr[j]<<" ";
	    	}
    	}


    	cout<<endl;
    }

    return 0;
}

