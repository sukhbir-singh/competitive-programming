#include <bits/stdc++.h>
using namespace std;

int wt[1000000],len[1000000];
int diff[1000000];

typedef pair<int, int> pii;

struct compare {
	bool operator()(const pii& l, const pii& r){
		return l.first > r.first;
	}
};

int main(int argc, char const *argv[])
{
	int times;
	scanf("%d",&times);

	map<int,int> check;
	map<int,priority_queue<pii,vector<pii>,compare> > mp;
	
	for(int i=0;i<times;i++){

		scanf("%d%d",&wt[i],&len[i]);

		diff[i]=len[i]-wt[i];
		
		if(check[diff[i]]==0){
			priority_queue<pii,vector<pii>,compare> top_pq;
			top_pq.push(make_pair(wt[i]*(-1),len[i]));

			mp[diff[i]]=top_pq;
			check[diff[i]]=1;
		}else{
			priority_queue<pii,vector<pii>,compare> top_pq1;
			top_pq1=mp[diff[i]];

			top_pq1.push(make_pair(wt[i]*(-1),len[i]));			

			mp[diff[i]]=top_pq1;
			check[diff[i]]=check[diff[i]]+1;
		}

	}

	long long ans=0;
	long long count=0;

	typedef map<int,priority_queue<pii,vector<pii>,compare> >::iterator it_type;
	for(it_type iterator = mp.begin(); iterator != mp.end(); iterator++) {

		priority_queue<pii,vector<pii>,compare> temp;

		temp=iterator->second;

		while(!temp.empty()){
			count+=temp.top().second;

			ans=ans+temp.top().first*(-1)*count;

			temp.pop();
		}

	}

	printf("ANSWER: %lld\n", ans);
}
