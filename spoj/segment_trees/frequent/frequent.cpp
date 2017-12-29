#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

lg arr[100005];
class node{
public:
	pii left;
	pii right;
	pii best;
};
node segment[100005*4];

node merge_node(node n1,node n2){
	node n;
	if(n1.best.second>=n2.best.second){
		n.best=n1.best;
	}else{
		n.best=n2.best;
	}
	if(n1.right.first == n2.left.first){
		if(n1.right.second+n2.left.second > n.best.second){
			n.best=mkp(n1.left.first,n1.right.second+n2.left.second);
		}
	}
	n.left=n1.left;
	n.right=n2.right;

	if(n1.left.first==n2.right.first){
		n.left.second=n1.left.second+n2.right.second;
		n.right.second=n.left.second;
	}else if(n1.left.first==n2.left.first){
		n.left.second=n1.left.second+n2.left.second;
	}

	if(n1.right.first==n2.right.first){
		n.right.second=n2.right.second+n1.right.second;
	}

	return n;
}

void build_tree(lg low,lg high,lg pos){
	if(low==high){
		node n;
		pii p=mkp(arr[low],1);
		n.left=p;
		n.right=p;
		n.best=p;
		segment[pos]=n;
		return;
	}
	lg mid=(low+high)/2;
	build_tree(low,mid,2*pos+1);
	build_tree(mid+1,high,2*pos+2);

	segment[pos]=merge_node(segment[2*pos+1],segment[2*pos+2]);
}

node query(lg ql,lg qh,lg low,lg high,lg pos){
	if(ql>high || qh<low){
		node n;
		n.left=mkp(0,0);
		n.right=mkp(0,0);
		n.best=mkp(0,0);
		return n;

	}else if(ql<=low && high<=qh){
		return segment[pos];
	}

	lg mid=(low+high)/2;
	node n1,n2,n;
	n1=query(ql,qh,low,mid,2*pos+1);
	n2=query(ql,qh,mid+1,high,2*pos+2);

	return merge_node(n1,n2);
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,q,l,r;

    while(1){
    	cin>>n;
    	if(n==0){
    		break;
    	}

    	cin>>q;
    	fr(i,0,n){
    		cin>>arr[i];
    	}

    	build_tree(0,n-1,0);

    	fr(j,0,q){
	    	cin>>l>>r;
	    	cout<<query(l-1,r-1,0,n-1,0).best.second<<endl;
    	}    	
    }

    return 0;
}
