#include<bits/stdc++.h>
using namespace std;
#define F(i,l,h) for(int (int)i=l;i<h;i++)

typedef long long ll;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false); 

	ll t,n,c,temp;
	cin>>t;

	while(t>0){
		t--;
		cin>>n>>c;
		ll n1=n;

		vector<ll> v;

		while(n>0){
			n--;
			cin>>temp;
			v.push_back(temp);
		}

		sort(v.begin(),v.end());

		ll mid=0,low=1,high=v.at(v.size()-1)-v.at(0);

		while(low<high){
			mid=low+(high-low+1)/2;
			ll last=v.at(0),temp_c=1;
			ll flag=0;

			//predicate
			for(ll i=1;i<n1;i++){
				if(v.at(i)-last >= mid){
					last=v.at(i);
					temp_c++;
				}

				if(temp_c>=c){
					flag=1;
					break;
				}
			}

			if(temp_c>=c){
				flag=1;
			}

			if(flag==1){
				low=mid;
			}else{
				high=mid-1;
			}

		}

		cout<<low<<endl;
	}

	return 0;
}
