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
		char ch;
		node *left;
		node *right;
};

node root;
node n1;

lg arr[400000];
lg bits=0;

void insert_word(node *nd, lg value, lg index){
	if(index<0) return;
cout<<"bit is "<<(value&(1<<index))<<" for index: "<<index<<" value: "<<value<<endl;
	if((value&(1<<index))==0){
		if(nd->left==0){
			node np;
			np.ch='0';
			nd->left=&np;
		}

		insert_word(nd->left, value, index-1);
	}else{
		if(nd->right==0){
			node np;
			np.ch='1';
			nd->right=&np;
		}

		insert_word(nd->right, value, index-1);
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,q,m,x,y;
    cin>>t;

    fr(i,0,t){
    	cin>>arr[i];
    }

	double temp=log2(t*1.0);

	if((temp-(lg)temp)>0){
		bits++;
	}
	bits+=(lg)temp;

	fr(i,0,t){		
    	insert_word(&root,i,18l); // 0 to t-1
	}

    // cout<<(root.left==0)<<endl;
    // cout<<(root.right==0)<<endl;

    cin>>q;
    while(q--){
    	cin>>x>>y;

    }

    return 0;
}
