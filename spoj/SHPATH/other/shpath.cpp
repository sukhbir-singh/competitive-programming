#include <bits/stdc++.h>
using namespace std;
#define inf 99999999

class edge{
	public: 
		int src;
		int dest;
		int wt;
};

int dijkstra(int from, int to, vector<edge> vertices[],
     int parent[],int keys[], int visit[]){

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

		edge e=mp[-1*t].front();
		mp[-1*t].pop_front();

		int sum1=e.wt+keys[e.src];

		if(sum1<keys[e.dest]){
			parent[e.dest]=e.src;

			keys[e.dest]=sum1;
		}

		if(visit[e.dest]==1){
			continue;
		}

		int len=vertices[e.dest].size();

		for(int i=0;i<len;i++){
			edge e1=vertices[e.dest][i];

			mp[e1.wt].push_back(e1);
			q.push(-1*e1.wt);

		}

		visit[e.dest]=1;

	}

	return keys[to];

}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);

	int times,v,k,n_cities;
	cin>>times;

	for(int i=0;i<times;i++){
		cin>>v;
		string tmp;
		vector<edge> vertices[v+1];

		map<string,int> city_names;

		int parent[v+1];
		int keys[v+1];

		for(int j=1;j<=v;j++){
			
			cin>>tmp;

			city_names[tmp]=j;

			int num;
			cin>>num;

			for(int k=0;k<num;k++){
				int t1,t2;
				cin>>t1;
				cin>>t2;

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

			int visit[v+1];

			int from=city_names[s1],to=city_names[s2];
			
			printf("from : %d to : %d\n",from,to );	

			int rt=dijkstra(from,to,vertices,parent,keys,visit);

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