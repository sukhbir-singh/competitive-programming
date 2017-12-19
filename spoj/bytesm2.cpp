#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rfr(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
typedef long long lg;

map<pair<int,int>,int> mp;
int h,w;
int arr[151][151];

int calc(int s1,int s2){
	if(mp.find(make_pair(s1,s2))!=mp.end()){
		return mp[make_pair(s1,s2)];
	}

	if(s1==h-1){
		mp[make_pair(s1,s2)]=arr[s1][s2];	
		return arr[s1][s2];
	}else if(s1<0 || s1>=h || s2<0 || s2>=w){
		return 0;
	}

	int max1=max(calc(s1+1,s2-1),calc(s1+1,s2));
	int ans=arr[s1][s2]+max(max1,calc(s1+1,s2+1));

	mp[make_pair(s1,s2)]=ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); 
	lg n;
	cin>>n;

	while(n--){
		cin>>h>>w;

		//clear
		mp.clear();
		memset(arr,0,sizeof(arr));

		fr(i,0,h){
			fr(j,0,w){
				cin>>arr[i][j];
			}
		}

		int max_value=0;
		fr(j,0,w){
			max_value=max(max_value,calc(0,j));
		}

		cout<<max_value<<endl;
	}
}
