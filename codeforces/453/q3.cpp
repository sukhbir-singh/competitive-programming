#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rfr(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
typedef long long lg;

int main(){
    ios_base::sync_with_stdio(false); 
    lg h;
    cin>>h;
    int arr[h+1];
    lg sum=0;

    fr(i,0,h+1){
    	cin>>arr[i];
    	sum+=arr[i];
    }

    int flag=0;

    fr(i,0,h){
    	if(arr[i]>=2 && arr[i+1]>=2){
    		flag=i;	
    		break;
    	}
    }

    lg num=0;

    if(flag==0){
    	cout<<"perfect\n";
    }else{
    	cout<<"ambiguous\n";

    	int cumsum=0;

    	fr(i,0,h+1){
    		num=cumsum;

    		fr(j,0,arr[i]){
    			cout<<num<<" ";
    		}

    		cumsum+=arr[i];
    	}

    	cout<<endl;
    	num=0;
    	cumsum=0;

    	fr(i,0,h+1){
    		num=cumsum;
    		lg temp=0;

    		fr(j,0,arr[i]){
    			if(i==flag+1){
    				cout<<num-temp<<" ";
    				
    				if(temp<arr[i-1]-1){
    					temp++;		
    				}
    			}else{
    				cout<<num<<" ";
    			}
    			
    		}

    		cumsum+=arr[i];
    	}

    }
    return 0;
}

