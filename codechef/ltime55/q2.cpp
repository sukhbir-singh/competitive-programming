#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;

lg sum(lg n){
	lg s=0;
	while(n>0){
		s+=n%10;
		n/=10;
	}

	if(s>=10){
		return sum(s);
	}else{
		return s;
	}
}

lg pww(lg x,lg y){
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return pww(x, y/2)*pww(x, y/2);
    else
        return x*pww(x, y/2)*pww(x, y/2);
}

int main(){
	// fr(i,1,15){
	// 	cout<<i<<" "<<sum(pow(9,i))<<endl;
	// }

    ios_base::sync_with_stdio(false); 
    lg t,n,m,a;
    cin>>t;

    fr(i,0,t){
    	cin>>a>>n;

    	lg temp=sum(a);
    	lg pp;

    	if(temp==0 || temp==1){
    		cout<<temp<<endl;
    		continue;
    	}else if(temp==2){
    		cout<<sum(pow(2,n%6))<<endl;
    		continue;
    	}else if(temp==3){
    		if(n==1){
    			pp=3;
    		}else{
    			pp=9;
    		}
    	}else if(temp==4){    		
    		pp=sum(pow(4,n%3));
    	}else if(temp==5){
    		pp=sum(pow(temp,n%6));
    	}else if(temp==6){
    		if(n==1){
    			pp=6;
    		}else{
    			pp=9;
    		}
    	}else if(temp==7){
    		pp=sum(pow(temp,n%3));
    	}else if(temp==8){
    		if(n%2==0){
    			pp=1;
    		}else{
    			pp=8;
    		}
    	}else if(temp==9){
    		pp=9;
    	}

    	// lg pp=pww(temp,n);
    	// pp=sum(pp);

    	cout<<pp<<endl;
    }

    return 0;
}

