#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rfr(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<int,int> pii;

queue<pii> states;
map<pii,int> mp;
map<pii,pii> parent;
map<pii,int> rem;

void bfs(int n){
	states.push(mkp(0,0));

	while(!states.empty()){
		pii p=states.front();
		// cout<<"#"<<p.first<<"-"<<p.second<<endl;

		if(p.first==n && p.second==0){
			break;
		}

		mp[p]=2;
		states.pop();

		fr(i,0,10){
			pii tt=mkp(p.first+i,(p.second*10+i)%n);
			if(mp[tt]==0){
				parent[tt]=p;
				rem[tt]=i;
				states.push(tt);
				mp[tt]=1;
			}
		}
	}

	//backtrack
	int i1=n,i2=0;
	cout<<"i1: "<<i1<<", i2: "<<i2<<" | "<<rem[mkp(i1,i2)]<<endl;
	while(i1!=0 || i2!=0){
		pii tp=parent[mkp(i1,i2)];
		i1=tp.first;
		i2=tp.second;
		cout<<"i1: "<<i1<<", i2: "<<i2<<" | "<<rem[mkp(i1,i2)]<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>t;

    fr(i,0,t){
    	cin>>n;
    	states=queue<pii>();
    	parent.clear();
    	mp.clear();
    	bfs(n);
    }

    return 0;
}


