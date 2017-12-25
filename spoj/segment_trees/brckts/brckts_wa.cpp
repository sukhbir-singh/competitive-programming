#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;
string s;

class node{
public:
	bool bl;
	lg diff;
};

node segment[30005*4];

node merge(node n1,node n2){
	node n;
	n.diff=n1.diff+n2.diff;

	lg a1=n1.diff;
	lg a2=n2.diff;

	if(a1==0 && a2==0){
		if(n1.bl && n2.bl){
			n.bl=true;
		}else{
			n.bl=false;
		}
	}else if(a1==0 || a2==0){
		n.bl=false;
	}else if(a2>a1){
		n.bl=false;
	}else if(a1>=a2){
		if((a1+a2) == 0){
			n.bl=true;
		}else{
			n.bl=false;
		}
	}
	
	return n;

}

void build_tree(lg low,lg high,lg pos){
	if(low==high){
		node n;		
		if(s[low]=='('){
			n.diff=1;
		}else{
			n.diff=-1;
		}
		n.bl=false;
		segment[pos]=n;
		return;
	}
	lg mid=(low+high)/2;
	build_tree(low,mid,2*pos+1);
	build_tree(mid+1,high,2*pos+2);

	segment[pos]=merge(segment[2*pos+1],segment[2*pos+2]);
}

bool check(){
	node n=segment[0];
	if(n.diff!=0){
		return false;
	}

	return n.bl;
}

void update(lg k,lg low,lg high,lg pos){
	if(low==high){
		segment[pos].diff=segment[pos].diff*(-1);
		return;
	}

	lg mid=(low+high)/2;
	if(k<=mid){
		update(k,low,mid,2*pos+1);
	}else{
		update(k,mid+1,high,2*pos+2);
	}

	segment[pos]=merge(segment[2*pos+1],segment[2*pos+2]);
	// cout<<"for pos "<<pos<<", new diff is "<<segment[pos].diff<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m,k;

    fr(i,0,10){
    	cin>>n;
    	cin>>s;

    	build_tree(0,n-1,0);
		cout<<"initially "<<segment[0].bl<<" : "<<segment[0].diff<<endl;

    	cout<<"TEST "<<i+1<<":"<<endl;
    	
    	cin>>m;
    	fr(j,0,m){
    		cin>>k;
    		if(k==0){
    			if(check()){
    				cout<<"YES\n";
    			}else{
    				cout<<"NO\n";
    			}
    		}else{
    			update(k-1,0,n-1,0);
    			// cout<<"yo "<<segment[0].diff<<endl<<endl;
    		}
    	}    	
    }

    return 0;
}

