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
	lg left;
	lg right;
};

node segment[30005*4];

node merge(node n1,node n2){
	node n;
	lg l=0,r=0;

	l=n1.left;
	r=n2.right;

	lg m=min(n1.right,n2.left);
	
	n.left=l+n2.left-m;
	n.right=r+n1.right-m;
	return n;
}

void build_tree(lg low,lg high,lg pos){
	if(low==high){
		node n;		
		if(s[low]=='('){
			n.left=0;
			n.right=1;
		}else{
			n.left=1;
			n.right=0;
		}
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
	if(n.left==0 && n.right==0){
		return true;
	}else{
		return false;
	}
}

void update(lg k,lg low,lg high,lg pos){
	if(low==high){
		node n;
		n.left=1-segment[pos].left;
		n.right=1-segment[pos].right;
		segment[pos]=n;
		return;
	}

	lg mid=(low+high)/2;
	if(k<=mid){
		update(k,low,mid,2*pos+1);
	}else{
		update(k,mid+1,high,2*pos+2);
	}

	segment[pos]=merge(segment[2*pos+1],segment[2*pos+2]);
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m,k;

    fr(i,0,10){
    	cin>>n;
    	cin>>s;

    	build_tree(0,n-1,0);

    	cout<<"Test "<<i+1<<":"<<endl;
    	
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
    		}
			
    	}    	
    }

    return 0;
}

