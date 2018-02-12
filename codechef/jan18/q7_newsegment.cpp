#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
#define NINF LONG_MIN
typedef long long lg;
typedef pair<lg,lg> pii;
int add(int x,int y){int res=(x+0LL+y)%MOD;return (res<0)?res+MOD:res;}
 
class node{
	public:
		lg count=0;
		lg mx=-1;
		lg binary=0;
};
 
lg arr[400000];
node segment[4*400000];
lg t=0;
 
node merge_node(node n1,node n2){
	node n;
	n.count=n1.count+n2.count;
	n.binary=n1.binary&n2.binary;
	n.mx=max(n1.mx,n2.mx);
	return n;
}
 
void build_tree(lg low,lg high,lg pos){	
	if(low==high){
		node n;
		if(arr[low]>0){
			n.count=1;
		}else{
			n.count=0;
		}

		n.mx=arr[low];
 
		n.binary=low;
		segment[pos]=n;
		return;
	}
 
	lg mid=(low+high)/2;
	build_tree(low,mid,2*pos+1);
	build_tree(mid+1,high,2*pos+2);
 
	segment[pos]=merge_node(segment[2*pos+1],segment[2*pos+2]);
}
 
void update(lg index,lg x,lg y,lg low,lg high,lg pos){
	if(segment[pos].count==0) return;
 
	if(low==high){
		arr[low]=arr[low]-y;
		segment[pos].mx=arr[low];
 
		if(arr[low]<=0){			
			segment[pos].count=0;
		}else{
			segment[pos].count=1;
		}
		return;
	}
	lg mid=(low+high)/2;

	lg value=(1<<(index+1))-1;

	if((value&x)==value && segment[pos].mx<=y){
		segment[pos].count=0;
		return;
	}
 
	if((x&(1<<index))==0){ 
		update(index-1,x,y,low,mid,2*pos+1);
	}else{ 
		update(index-1,x,y,low,mid,2*pos+1);
		update(index-1,x,y,mid+1,high,2*pos+2);
	}
 
	segment[pos]=merge_node(segment[2*pos+1],segment[2*pos+2]);
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    lg n,q,m,x,y;
    cin>>t;    
 
    fr(i,0,t){
    	cin>>arr[i];
    }
 
	lg bits=0;
	double temp=log2(t*1.0);
	if((temp-(lg)temp)>0){
		bits++;
	}
	
	bits+=(lg)temp;
 
	lg max_index=pow(2,bits)-1;
    build_tree(0,max_index,0);
 
    cin>>q;
    while(q--){
    	cin>>x>>y;		
    	update(bits-1,x,y,0,max_index,0);
 
    	cout<<segment[0].count<<endl;
    }
    return 0;
}