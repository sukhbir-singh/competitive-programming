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

vector<edge> vertices[10000+2];

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

	int times,v,k;
	cin>>times;

	for(int i=0;i<times;i++){
		cin>>v;

		map<string,int> names;

		for(int j=1;j<=v;j++){
			string temp1;
			cin>>temp1;

			vertices[j].clear();

			names[temp1]=j;

			int num;
			cin>>num;

			for(int k=0;k<num;k++){
				int t1,t2;
				cin>>t1>>t2;

				edge e;
				e.src=j;
				e.dest=t1;
				e.wt=t2;

				vertices[j].push_back(e);
			}
		}

		int operations;
		cin>>operations;

		for(int k=0;k<operations;k++){
			string s1,s2;
			cin>>s1>>s2;

			int from=names[s1],to=names[s2];
			
			int rt=dijkstra(from,to,v);

			if(rt==inf){
				cout<<"NO\n";
			}else{
				cout<<rt<<endl;
			}

		}

	}

	return 0;
}