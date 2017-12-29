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
	map<lg,lg> f;
};
node segment[100005*4];
 
node merge_node(node n1,node n2){
	node n;
	map<lg,lg> mp1,mp2,m;
	mp1=n1.f;
	mp2=n2.f;
 
	for(auto it = mp1.cbegin(); it != mp1.cend(); ++it ){
		m[it->first]=mp1[it->first];
	}
	for(auto it = mp2.cbegin(); it != mp2.cend(); ++it ){
		m[it->first]=m[it->first]+mp2[it->first];
	}
 
	n.f=m;
	return n;
}
 
 
void build_tree(lg low,lg high,lg pos){
	if(low==high){
		node n;
		map<lg,lg> mp;
		mp[arr[low]]=1;
		n.f=mp;
		segment[pos]=n;
		return;
	}
	lg mid=(low+high)/2;
	build_tree(low,mid,2*pos+1);
	build_tree(mid+1,high,2*pos+2);
 
	segment[pos]=merge_node(segment[2*pos+1],segment[2*pos+2]);
}
 
map<lg,lg> query(lg ql,lg qh,lg low,lg high,lg pos){
	if(ql>high || qh<low){
		map<lg,lg> m;
		return m;
 
	}else if(ql<=low && high<=qh){
		return segment[pos].f;
	}
 
	lg mid=(low+high)/2;
 
	map<lg,lg> m1,m2;
	m1=query(ql,qh,low,mid,2*pos+1);
	m2=query(ql,qh,mid+1,high,2*pos+2);
 
	node n1,n2;
	n1.f=m1;
	n2.f=m2;
	node n=merge_node(n1,n2);
	return n.f;
}
 
lg get_max(map<lg,lg> mp){
	lg max1=0;
	for(auto it = mp.cbegin(); it != mp.cend(); ++it ){
		if(it->second >= max1){
			max1=it->second;
		}
	}
	return max1;
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
	    	cout<<get_max(query(l-1,r-1,0,n-1,0))<<endl;
    	}    	
    }
 
    return 0;
}