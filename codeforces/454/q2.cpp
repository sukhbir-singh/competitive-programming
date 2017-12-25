#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

int arr[9][9];

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    string s;
    
    int count=-1;

    fr(j,0,11){
    	getline(cin,s);

    	if(s.length()<3){
    		continue;
    	}
    	count++;
    	int c2=-1;

    	fr(i,0,s.length()){
    		if(s[i]==' '){
    			continue;
    		}
    		c2++;
    		if(s[i]=='x'){
    			arr[count][c2]=1;
    		}else if(s[i]=='o'){
    			arr[count][c2]=2;
    		}
	    }	
    }
    
    lg x,y;
    cin>>x>>y;

    int last;
    if(arr[x-1][y-1]=='x'){
    	last=1;
    }else{
    	last=2;
    }

    x=x-1;
    x=x%3;
    y=y-1;
    y=y%3;

    int empty=0;

    // cout<<"from "<<x*3+y*3<<" to "<<x*3+y*3+3<<endl; 

    fr(i,x*3,x*3+3){
    	fr(j,y*3,y*3+3){
    		if(arr[i][j]==0){
    			empty=1;
    			arr[i][j]=11;
    		}    		
    	}
    }
    
    // cout<<"empty: "<<empty<<endl;

	fr(i,0,9){
		fr(j,0,9){
			if(arr[i][j]==0){
				if(empty==0){
					cout<<"!";	
				}else{
					cout<<".";
				}
				
			}else if(arr[i][j]==1){
				cout<<"x";
			}else if(arr[i][j]==2){
				cout<<"o";
			}else if(arr[i][j]==11){
				cout<<"!";
			}

			if(j%3==2){
				cout<<" ";
			}else if(j==8){
				cout<<endl;
			}

		}

		if(i%3==2){
			cout<<endl;
		}
		cout<<endl;
	}

    return 0;
}

