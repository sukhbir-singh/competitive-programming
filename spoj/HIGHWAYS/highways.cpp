#include <bits/stdc++.h>
using namespace std;
#define inf 99999999

class edge{
	public: 
		int src;
		int dest;
		int wt;
};

typedef pair<int, int> pii;

vector<edge> vertices[1000000+2];

struct compare {
	bool operator()(const pii& l, const pii& r){
		return l.first > r.first;
	}
};

int dijkstra(int from, int to, int v){

	int keys[v+1];
	int visit[v+1];

	for(int i=0;i<=v;i++){
		visit[i]=0;
		keys[i]=inf;
	}

	priority_queue<pii,vector<pii>,compare> pq;
	//check.push(make_pair(11,e1));

	keys[from]=0;

	pq.push(make_pair(keys[from],from));

	while(!pq.empty()){

		int vertex=pq.top().second;
		pq.pop();

		//cout<<"poped "<<e.src<<" "<<e.dest<<" "<<e.wt<<endl;

		int len1=vertices[vertex].size();

		for(int i=0;i<len1;i++){

			edge e1=vertices[vertex][i];

			if(e1.wt+keys[vertex]<keys[e1.dest]){

				keys[e1.dest]=e1.wt+keys[e1.src];
				pq.push(make_pair(keys[e1.dest],e1.dest));

			}	
		}

		if(visit[vertex]==1){
			continue;
		}

		if(vertex==to){
			return keys[to];
		}

		visit[vertex]=1;

	}

	//printf("minimum to %d : %d\n",to,keys[to]);
	return keys[to];

}	

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);

	int times,v,k,n,m,start,end;
	cin>>times;

	for(int i=0;i<times;i++){
		cin>>n>>m>>start>>end;

		for(int j=0;j<=n;j++){
			vertices[j].clear();
		}

		for(int j=0;j<m;j++){
			int t1,t2,t3;
			edge e;

			cin>>e.src>>e.dest>>e.wt;

			edge e1;
			e1.src=e.dest;
			e1.dest=e.src;
			e1.wt=e.wt;

			vertices[e.src].push_back(e);
			vertices[e1.src].push_back(e1);
		}

		int rt= dijkstra(start,end,n);

		if(rt==inf){
			cout<<"NONE\n";
		}else{
			cout<<rt<<endl;
		}

	}

	return 0;
}