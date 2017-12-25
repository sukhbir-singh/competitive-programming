#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

int arr[50005];
int segment[50005*5];
int n;
map<int,int> mp;
vector<vector<int> > v;

void build_tree(lg low,lg high,lg pos){	
	if(low==high){
		segment[pos]=arr[low];
		return;
	}	
	lg mid=(low+high)/2;
	build_tree(low,mid,2*pos+1);
	build_tree(mid+1,high,2*pos+2);
	
	lg s1=segment[2*pos+1];
	lg s2=segment[2*pos+2];

	if((mp[2*pos+1]==0 && mp[2*pos+2]==0)&&((s1>=0 && s2>=0)||(s1<0 && s2<0))){
		segment[pos]=s1+s2;	
	}else{
		int index=v.size();
		mp[pos]=index+1;
		vector<int> v1;

		if(mp[2*pos+1]!=0 || mp[2*pos+2]!=0){
			int ind1=mp[2*pos+1];
			int ind2=mp[2*pos+2];

			if(ind1==0){
				v1.push_back(s1);
			}else{
				int temp=v[ind1-1].size();
				fr(k1,0,temp){
					v1.push_back(v[ind1-1][k1]);
				}
			}

			if(ind2==0){
				v1.push_back(s2);
			}else{
				int temp=v[ind2-1].size();
				fr(k1,0,temp){
					v1.push_back(v[ind2-1][k1]);
				}
			}

		}else{
			v1.push_back(s1);
			v1.push_back(s2);
		}		
		
		v.push_back(v1);
		segment[pos]=-1;
	}
}

vector<int> query(int ql, int qh, lg low, lg high, lg pos){
	if(ql<=low && high<=qh){
		if(mp[pos]==0){
			vector<int> v2;
			v2.push_back(segment[pos]);
			return v2;
		}else{
			return v[mp[pos]-1];
		}

	}else if(ql>high || low>qh){
		return vector<int>();
	}else{
		int mid=(low+high)/2;
		vector<int> v1=query(ql,qh,low,mid,2*pos+1);
		vector<int> v2=query(ql,qh,mid+1,high,2*pos+2);

		vector<int> v3;

		if(v1.size()==1 && v2.size()==1){
			v3.push_back(v1[0]+v2[0]);
			return v3;
		}

		int l1=v1.size(),l2=v2.size();
		fr(i,0,l1){
			v3.push_back(v1[i]);
		}
		fr(i,0,l2){
			v3.push_back(v2[i]);	
		}

		return v3;
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg m,x,y;

	cin>>n;
	fr(j,0,n){
		cin>>arr[j];
	}
	//build tree
	build_tree(0,n-1,0);

	cin>>m;
	fr(j,0,m){
		cin>>x>>y;
		vector<int> rtn=query(x-1,y-1,0,n-1,0);

		//now calculate largest contiguous sum
		int current_sum=rtn[0];
		int max_sum=rtn[0];
		int l=rtn.size();

		fr(tt,1,l){
			current_sum=max(current_sum+rtn[tt],rtn[tt]);
			max_sum=max(current_sum,max_sum);
		}

		cout<<max_sum<<endl;
	}

    return 0;
}

