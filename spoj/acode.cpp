#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rfr(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)

int main(int argc, char const *argv[]){
	typedef long long lg;
    ios_base::sync_with_stdio(false); 
    string s;

    while(1){
    	cin>>s;
    	if(s=="0"){
    		break;
    	}

    	lg l=s.length();
    	
    	// for storing number of singles and using it in next lower index interations
    	lg single[l]; 

    	fr(i,0,l){
    		single[i]=0;
    	}

    	int flag=0;

    	//initial check for validity of string
    	fr(i,0,l-1){
    		if((s[i+1]=='0' && s[i]=='0')||(s[i+1]=='0' && s[i]>='3')){
    			flag=1;
    			break;
    		}
    	}

    	if(flag==1){
    		cout<<"0"<<endl;
    		continue;
    	}

    	long long total=0;

    	rfr(i,l-1,0){
    		if(s[i]=='0'){
    			continue;
    		}

    		if(i==l-1){
    			single[l-1]=1;
    			total=1;
    			continue;
    		}

    		single[i]=total;
    		
    		if(s[i+1]=='0'){
    			if(total==0){
    				total+=1;	
    			}
    			single[i]=0;
    			continue;
    		}

    		lg value=0;

    		if(((s[i]-'0')*10+(s[i+1]-'0'))<=26){
    			value=single[i+1];
    		}
    		
    		total=total+value;
    	}

    	cout<<total<<endl;
    }
}