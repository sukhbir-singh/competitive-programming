#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

class node{
	public:
		lg s;
		lg ms; 
		lg lm;
		lg rm;
};

int arr[50005];
node segment[50005*5];
int n;

void build_tree(lg low, lg high, lg pos){
	if(low==high){
		node n;
		n.s=arr[low];
		n.ms=arr[low];
		n.lm=arr[low];
		n.rm=arr[low];
		segment[pos]=n;

		return;
	}
	
	int mid=(low+high)/2;
	build_tree(low,mid,2*pos+1);
	build_tree(mid+1,high,2*pos+2);

	node left=segment[2*pos+1];
	node right=segment[2*pos+2];
	
	node n1;
	n1.s=left.s+right.s;
	n1.ms=max(max(left.ms,right.ms), left.rm+right.lm);
	n1.lm=max(left.lm, left.s+right.lm);
	n1.rm=max(right.rm, right.s+left.rm);

	segment[pos]=n1;
}

node query(lg ql,lg qh,lg low,lg high,lg pos){
	if(ql<=low && high<=qh){
		return segment[pos];

	}else if(ql>high || qh<low){ // condition important
		node n3;
		n3.s=INT_MIN;
		n3.ms=INT_MIN;
		n3.lm=INT_MIN;
		n3.rm=INT_MIN;

		return n3;
	}else{

		lg mid=(low+high)/2;
		node n1=query(ql,qh,low,mid,2*pos+1);
		node n2=query(ql,qh,mid+1,high,2*pos+2);

		node n;

		if(n1.s==INT_MIN){
			n=n2;
		}else if(n2.s==INT_MIN){
			n=n1;
		}else{
			n.s=n1.s+n2.s;
			
			n.ms=max(max(n1.ms,n2.ms), n1.rm+n2.lm);
			n.lm=max(n1.lm,n1.s+n2.lm);
			n.rm=max(n2.rm,n2.s+n1.rm);
		}

		return n;
	}
}

void single_update(lg low, lg high, lg pos,lg index, lg value){
	if(low==high){
		node n;
		n.s=value;
		n.ms=value;
		n.lm=value;
		n.rm=value;
		segment[pos]=n;

		return;
	}
	
	int mid=(low+high)/2;

	if(index<=mid){
		single_update(low,mid,2*pos+1,index,value);
	}else{
		single_update(mid+1,high,2*pos+2,index,value);
	}

	node left=segment[2*pos+1];
	node right=segment[2*pos+2];
	
	node n1;
	n1.s=left.s+right.s;
	n1.ms=max(max(left.ms,right.ms), left.rm+right.lm);
	n1.lm=max(left.lm, left.s+right.lm);
	n1.rm=max(right.rm, right.s+left.rm);

	segment[pos]=n1;
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg m,x,y,t;

	cin>>n;
	fr(j,0,n){
		cin>>arr[j];
	}
	
	build_tree(0,n-1,0);

	cin>>m;
	fr(j,0,m){
		cin>>t>>x>>y;
		if(t==0){
			single_update(0,n-1,0,x-1,y);
		}else{
			cout<<query(x-1,y-1,0,n-1,0).ms<<endl;
		}
		
	}

    return 0;
}

