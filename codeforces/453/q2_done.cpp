#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rfr(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
typedef long long lg;

int visit[100000];
int color[100000];
int current[100000];

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>n;

    vector<int> vertices[n+1];

    fr(i,0,n-1){
    	cin>>t;
    	vertices[i+2].push_back(t);
		vertices[t].push_back(i+2);    	
    }

    fr(i,0,n){
    	cin>>color[i+1];
    }

    lg steps=1;

    //bfs
    current[1]=color[1];
    queue<int> q;

    fr(i,0,vertices[1].size()){
    	q.push(vertices[1][i]);
    	current[vertices[1][i]]=color[1];
    	visit[vertices[1][i]]=1;
    }

    visit[1]=2;

    while(!q.empty()){
    	t=q.front();
    	q.pop();
    	visit[t]=2;

    	if(current[t]!=color[t]){
    		steps++;
    	}

    	current[t]=color[t];

		fr(i,0,vertices[t].size()){
			if(visit[vertices[t][i]]==0){
				q.push(vertices[t][i]);
				current[vertices[t][i]]=color[t];
				visit[vertices[t][i]]=1;
			}
	    }
    }

    cout<<steps<<endl;

    return 0;
}





