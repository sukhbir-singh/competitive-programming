#include <bits/stdc++.h>
using namespace std;

class edge{
public:
	int i,j,w;
};

typedef pair<int, edge> pii;

int parent[100000];

struct compare {
	bool operator()(const pii& l, const pii& r){
		return l.first > r.first;
	}
};

int find1(int i){
	if(parent[i]==i){
		return parent[i];
	}else{
		return find1(parent[i]);
	}
}

void union1(int i,int j){
	parent[find1(i)]=find1(j);
}

int main(int argc, char const *argv[])
{
	typedef long long lg;
	lg n,m;

	scanf("%lld%lld",&n,&m);

	priority_queue<pii,vector<pii>,compare> pq;

	map<int,int> mp;

	for(lg i=0;i<n;i++){
		parent[i]=i;
	}

	for(lg i=0;i<m;i++){
		lg a,b,c;

		scanf("%lld%lld%lld",&a,&b,&c);

		edge e;
		e.i=a;
		e.j=b;
		e.w=c;

		pq.push(make_pair(c,e));

	}

	long long total=0;

	set<int> st;

	edge temp1=pq.top().second;
	parent[temp1.i]=temp1.i;
	parent[temp1.j]=temp1.j;

	while(!pq.empty()){

		edge temp=pq.top().second;
		pq.pop();

		printf("wt: %d\n",temp.w);

		if(find1(temp.i) != find1(temp.j)){
			total+=temp.w;

			union1(temp.i,temp.j);

		}
		
	}

	printf("%lld\n",total );

}