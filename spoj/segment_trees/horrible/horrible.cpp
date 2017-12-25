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
		lg lazy;
};

node segment[4*100005];
lg arr[100005];

void build_tree(lg low,lg high,lg pos){
	if(low==high){
		node n;
		n.sum=0;
		n.lazy=0;
		segment[pos]=n;
		return;
	}

	lg mid=(low+high)/2;
	build_tree(low,mid,2*pos+1);
	build_tree(mid+1,high,2*pos+2);

	node n;
	n.sum=0;
	n.lazy=0;	
	segment[pos]=n;
}

void lazy_update(lg low,lg high,lg pos){
	segment[pos].sum=segment[pos].sum + segment[pos].lazy*(high-low+1);
	if(low!=high){
		segment[2*pos+1].lazy=segment[2*pos+1].lazy+segment[pos].lazy;
		segment[2*pos+2].lazy=segment[2*pos+2].lazy+segment[pos].lazy;
	}
	segment[pos].lazy=0;
}

void range_update(lg ql,lg qh,lg v,lg low,lg high,lg pos){
	if(segment[pos].lazy>0){
		lazy_update(low,high,pos);
	}

	if(ql<=low && high<=qh){
		segment[pos].sum=segment[pos].sum+(high-low+1)*v;
		if(high!=low){
			segment[2*pos+1].lazy=segment[2*pos+1].lazy+v;
			segment[2*pos+2].lazy=segment[2*pos+2].lazy+v;
		}
		return;		
	}else if(ql>high || qh<low){
		return;
	}

	lg mid=(low+high)/2;
	range_update(ql,qh,v,low,mid,2*pos+1);
	range_update(ql,qh,v,1+mid,high,2*pos+2);
	segment[pos].sum=segment[2*pos+1].sum+segment[2*pos+2].sum;
}

node query(lg ql,lg qh,lg low,lg high,lg pos){
	if(segment[pos].lazy>0){
		lazy_update(low,high,pos);
	}

	if(ql<=low && high<=qh){
		return segment[pos];
	}else if(ql>high || qh<low){
		node n;
		n.sum=0;
		n.lazy=0;
		return n;
	}

	lg mid=(low+high)/2;

	node n1=query(ql,qh,low,mid,2*pos+1);
	node n2=query(ql,qh,mid+1,high,2*pos+2);

	node n;
	n.lazy=0;
	n.sum=n1.sum+n2.sum;
	return n;
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m,c,b,p,q,v;
    cin>>t;

    fr(i,0,t){
    	cin>>n>>c;
    	memset(arr,0,sizeof(arr));

    	build_tree(0,n-1,0);

    	fr(j,0,c){
    		cin>>b;
    		if(b==0){
    			cin>>p>>q>>v;
    			range_update(p-1,q-1,v,0,n-1,0);
    		}else{
    			cin>>p>>q;
    			cout<<query(p-1,q-1,0,n-1,0).sum<<endl;
    		}
    	}
    }

    return 0;
}

