#include <bits/stdc++.h>
using namespace std;
#define inf 99999999

class edge{
	public: 
		int src;
		int dest;
		int wt;
};

edge extract_min(){
 edge e;
 return e;
}

void dijkstra(int from, int to, vector<edge> vertices[],
	vector<int> visited, int parent[],int keys[]){

	

}

int main(int argc, char const *argv[])
{
	int times,v,k;
	scanf("%d",&times);

	for(int i=0;i<times;i++){
		scanf("%d%d",&v,&k);

		vector<edge> vertices[v];
		vector<int> visted_vertexes;
		int parent[v];
		int keys[v];

		for(int j=0;j<k;j++){
			int t1,t2,t3;

			scanf("%d%d%d",&t1,&t2,&t3);

			edge e;
			e.dest=t2;
			e.wt=t3;
			vertices[t1-1].push_back(e);		
		}

		int from,to;
		scanf("%d%d",&from,&to);

		for(int j=0;j<v;j++){
			parent[j]=-1;
			keys[j]=inf;
		}

		dijkstra(from,to,vertices,visted_vertexes,parent,keys);


	}

	return 0;
}