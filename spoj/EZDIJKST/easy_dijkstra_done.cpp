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

int dijkstra(int from, int to, vector<edge> vertices[],
     int parent[],int keys[]){

	map<int,list<edge> > mp;
	map<int,int>::iterator iter;
	priority_queue<int> q;

	keys[from]=0;

	int len1=vertices[from].size();

	for(int i=0;i<len1;i++){
		edge e=vertices[from][i];

		mp[e.wt].push_back(e);
		//printf("pushed %d\n",e.wt );

		q.push(-1*e.wt);
	}

	while(!q.empty()){
		int t=q.top();
		q.pop();

		//printf("poped %d\n",t*(-1) );

		edge e=mp[-1*t].front();
		mp[-1*t].pop_front();

		//printf("%d + %d , %d\n", e.wt,keys[e.src], keys[e.dest]);

		if(e.wt+keys[e.src]<keys[e.dest]){
			parent[e.dest]=e.src;

			keys[e.dest]=e.wt+keys[e.src];

			//printf("updated %d keys to %d\n",e.dest,keys[e.dest] );
		}

		int len=vertices[e.dest].size();

		for(int i=0;i<len;i++){
			edge e1=vertices[e.dest][i];

			mp[e1.wt].push_back(e1);
			q.push(-1*e1.wt);

			//printf("pushed %d\n",e1.wt );
		}

		vertices[e.dest].clear();

		//printf("top: %d\n",t );
	}

	//printf("minimum to %d : %d\n",to,keys[to]);
	return keys[to];

}

int main(int argc, char const *argv[])
{
	int times,v,k;
	scanf("%d",&times);

	for(int i=0;i<times;i++){
		scanf("%d%d",&v,&k);

		vector<edge> vertices[v+1];
		int parent[v+1];
		int keys[v+1];

		for(int j=0;j<k;j++){
			int t1,t2,t3;

			scanf("%d%d%d",&t1,&t2,&t3);
			edge e;
			e.wt=t3;
			e.src=t1;
			e.dest=t2;

			vertices[t1].push_back(e);		
		}

		// check
		/*for(int j=1;j<=v;j++){
			printf("%d: ",j);

			for(int k=0;k<vertices[j].size();k++){
				printf("%d (%d) ",vertices[j][k].dest,vertices[j][k].wt);
			}

			printf("\n");
		}
		printf("\n");*/
		//

		int from,to;
		scanf("%d%d",&from,&to);

		keys[from]=0;

		for(int j=0;j<=v;j++){
			parent[j]=-1;
			keys[j]=inf;
		}

		int rt=dijkstra(from,to,vertices,parent,keys);

		if(rt==inf){
			printf("NO\n");
		}else{
			printf("%d\n",rt);
		}
	}

	return 0;
}