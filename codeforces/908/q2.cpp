#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;

string s;
lg px,py,ex,ey;
lg t,n,m;

string maze[100];


bool run(string st){
	map<lg,char> mp;
	mp[0]=st[0];
	mp[1]=st[1];
	mp[2]=st[2];
	mp[3]=st[3];

	int index=0;
	lg x=px,y=py;

	while(1){
		// cout<<"YO "<<s[index]-'0'<<endl;
		if(mp[s[index]-'0']=='L'){
			// cout<<"l";
			x--;
		}else if(mp[s[index]-'0']=='R'){
			// cout<<"r";
			x++;
		}else if(mp[s[index]-'0']=='U'){
			// cout<<"u";
			y--;
		}else if(mp[s[index]-'0']=='D'){
			// cout<<"d";
			y++;
		}

		if(x<0 || y<0 || y>=m || x>=n){
			return false;
		}else if(maze[x][y]=='#'){
			return false;
		}else if(x==ex && y==ey){
			return true;
		}

		if(++index==s.length()){
			break;
		}
	}

	if(x==ex && y==ey){		
		return true;
	}else{
		return false;
	}

}
lg count11=0;

void permute(string str, string rem){
    if (str.size() == 0){
    	if(run(rem)){
    		count11++;
    	}
        return;
    }
 
    for (int i = 0; i < str.size(); i++){
        permute(str.substr(1), rem + str[0]);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin>>n>>m;

    fr(i,0,n){
    	cin>>maze[i];

    	fr(j,0,maze[i].length()){
    		if(maze[i][j]=='S'){
    			px=i;
    			py=j;
    		}else if(maze[i][j]=='E'){
    			ex=i;
    			ey=j;
    		}
    	}
    }

    cin>>s;
    permute("LRUD","");

    cout<<count11<<endl;

    return 0;
}

