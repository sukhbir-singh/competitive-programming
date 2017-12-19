#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rfr(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
typedef long long lg;

int arr[150];

int main(){
    ios_base::sync_with_stdio(false); 

    lg t,n,m,s,f;
    cin>>n>>m;

    lg low=-1,high=-1;

    fr(i,0,n){
    	cin>>s>>f;

    	fr(j,s,f){
    		arr[j]=1;
    	}
    }

    int flag=0;

    fr(i,0,m){
    	if(arr[i]==0){
    		flag=1;
    		break;
    	}
    }

    // fr(i,0,20){
    // 	cout<<arr[i]<<" ";
    // }
    // cout<<"\n";

    if(flag==0){
    	cout<<"YES\n";
    }else{
    	cout<<"NO\n";
    }

    return 0;
}

