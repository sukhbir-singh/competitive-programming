#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

queue<pii> states;
int visit[3009][3009];
map<pii,pii> parent;
map<pii,lg> rem;
lg n;

void bfs(){
	states.push(mkp(0,0));
	memset(visit,0,sizeof(visit));
	int flag=0;
	pii tt;

	while(!states.empty()){
		pii p=states.front();

		if(p.first==n && p.second==0){
			break;
		}

		visit[p.first][p.second]=2;
		states.pop();

		flag=0;

		fr(i,0,10){
			tt=mkp(p.first+i,(p.second*10+i)%n);
			if(visit[tt.first][tt.second]==0){
				parent[tt]=p;
				rem[tt]=i;
				states.push(tt);
				visit[tt.first][tt.second]=2;
			}

			if(tt.first==n && tt.second==0){
				flag=1;
				break;
			}
		}

		if(flag==1){
			break;
		}
	}

	//backtrack
	lg i1=n,i2=0;
	stack<lg> stk;
	while(i1!=0 || i2!=0){		
		pii temp1=mkp(i1,i2);
		stk.push(rem[temp1]);
		pii tp=parent[temp1];
		i1=tp.first;
		i2=tp.second;
	}

	while(!stk.empty()){
		cout<<stk.top();
		stk.pop();
	}
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t;
    cin>>t;

    fr(i,0,t){
    	cin>>n;
    	states=queue<pii>();
    	parent=map<pii,pii>();
    	rem=map<pii,lg>();
    	bfs();
    }

    return 0;
}


