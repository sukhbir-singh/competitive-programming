#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

class node{
	public:
		lg sum;
		lg ones; 
};

lg arr[4*100002];
node segment[4*100002];
lg n;

node merge_node(node n1,node n2){
	node n;
	n.sum=n1.sum+n2.sum;
	n.ones=n1.ones+n2.ones;
	return n;
}

void build_tree(lg low,lg high,lg pos){
	if(low==high){
		node n;
		n.sum=arr[low];
		n.ones=(arr[low]==1);
		segment[pos]=n;
		return;
	}
	
	lg mid=(low+high)/2;
	build_tree(low,mid,2*pos+1);
	build_tree(mid+1,high,2*pos+2);

	segment[pos]=merge_node(segment[2*pos+1],segment[2*pos+2]);
}

node query(lg ql,lg qh,lg low,lg high,lg pos){
	if(ql<=low && high<=qh){
		return segment[pos];
	
	}else if(ql>high || qh<low){
		node n;
		n.sum=0;
		n.ones=0;
		return n;
	}

	lg mid=(low+high)/2;
	node n1=query(ql,qh,low,mid,2*pos+1);
	node n2=query(ql,qh,mid+1,high,2*pos+2);

	return merge_node(n1,n2);
}

void range_update(lg rl,lg rh,lg low,lg high,lg pos){	// important 
	if(rl>high || rh<low){
		return;
	}else if(low==high){
		segment[pos].sum=sqrt(segment[pos].sum);
		if(segment[pos].sum==1){
			segment[pos].ones=1;
		}
		return;
	}else if(high-low+1 == segment[pos].ones){
		return;
	}

	lg mid=(low+high)/2;
	range_update(rl,rh,low,mid,2*pos+1);
	range_update(rl,rh,mid+1,high,2*pos+2);	

	segment[pos]=merge_node(segment[2*pos+1],segment[2*pos+2]);
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg n,m,q,t,x,y,p;
    lg count=1;

    while(cin>>n){
	    fr(i,0,n){
    		cin>>arr[i];
	    }

	    build_tree(0,n-1,0);	
	    cin>>q;
	    cout<<"Case #"<<count++<<":"<<endl;

    	fr(j,0,q){
    		cin>>t>>x>>y;
    		if(x>y){
    			swap(x,y);
    		}
    		
    		if(t==0){
    			range_update(x-1,y-1,0,n-1,0);
    		}else{
    			cout<<query(x-1,y-1,0,n-1,0).sum<<endl;
    		}
    	}
    }

    return 0;
}

