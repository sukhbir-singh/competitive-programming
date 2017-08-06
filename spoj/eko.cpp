#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(int)a;i<b;i++)

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false); 
	ll n,m,temp;
	cin>>n>>m;

	vector<int> v;
	F(i,0,n){
		cin>>temp;
		v.push_back(temp);
	}

	sort(v.begin(),v.end());

	ll mid=0,low=0,high=v.at(v.size()-1);

	while(low<high){
		mid=low+(high-low+1)/2;

		//predicate
		temp=0;
		F(i,0,n){
			if(v.at(i)>mid){
				temp+=v.at(i)-mid;
			}
		}

		if(temp==m){
			low=mid;
			break;
		}else if(temp>m){
			low=mid;
		}else{
			high=mid-1;
		}
	}

	cout<<low<<endl;
	return 0;
}
