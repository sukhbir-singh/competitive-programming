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

vector<edge> vertices[10000+2];

int dijkstra(int from, int to, int v){

	int parent[v+1];
	int keys[v+1];
	int visit[v+1];

	for(int i=0;i<=v;i++){
		visit[i]=0;
		keys[i]=inf;
		parent[i]=-1;
	}

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

		if(visit[e.dest]==1){
			continue;
		}

		if(e.dest==to){
			break;
		}

		int len=vertices[e.dest].size();

		for(int i=0;i<len;i++){
			edge e1=vertices[e.dest][i];

			mp[e1.wt].push_back(e1);
			q.push(-1*e1.wt);

			//printf("pushed %d\n",e1.wt );
		}

		visit[e.dest]=1;
		//vertices[e.dest].clear();

		//printf("top: %d\n",t );
	}

	//printf("minimum to %d : %d\n",to,keys[to]);
	return keys[to];

}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);

	int times,v,k,n_cities;
	cin>>times;

	for(int i=0;i<times;i++){
		cin>>v;
		string names[v+1];

		for(int j=1;j<=v;j++){
			cin>>names[j];

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

		// check
		/*printf("\ncheck:-- \n");

		for(int j=1;j<=v;j++){
			printf("%d: ",j);

			for(int k=0;k<vertices[j].size();k++){
				printf("%d (%d) ",vertices[j][k].dest,vertices[j][k].wt);
			}

			printf("\n");
		}
		printf("\n");*/
		//

		int operations;
		cin>>operations;

		for(int k=0;k<operations;k++){
			string s1,s2;
			cin>>s1>>s2;


			int from,to;

			for(int j=1;j<=v;j++){

				if(s1==names[j]){
					from=j;
				}

				if(s2==names[j]){
					to=j;
				}
			}
			
			//printf("from : %d to : %d\n",from,to );	

			int rt=dijkstra(from,to,v);

			if(rt==inf){
				cout<<"NO\n";
			}else{
				cout<<rt<<endl;
			}

		}


		/*keys[from]=0;

		for(int j=0;j<=v;j++){
			parent[j]=-1;
			keys[j]=inf;
		}

		int rt=dijkstra(from,to,vertices,parent,keys);

		if(rt==inf){
			printf("NO\n");
		}else{
			printf("%d\n",rt);
		}*/
	}

	return 0;
}