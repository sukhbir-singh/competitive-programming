#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

lg n;

bool check(vector<int> v){
	stack<int> st;
	fr(i,0,2*n){
		if(st.empty()){
			st.push(v[i]);
		}else{

			if(st.top()==1 && v[i]==2){
				st.pop();
			}else{
				st.push(v[i]);
			}
		}
	}

	if(st.size()==0){
		return true;
	}else{
		return false;
	}
}

int count(vector<int> v,int index,int left,int right){
	// cout<<"index: "<<index<<", left: "<<left<<", right: "<<right<<endl;
	if(right>left){
		return 0;
	}

	if(index==-1){
		if(check(v)){
			return 1;
		}else{
			return 0;
		}
	}

	int next=-1;
	fr(j,index+1,2*n){
		if(v[j]==0){
			next=j;
			break;
		}else if(v[j]==1){
			left++;
		}else if(v[j]==2){
			right++;
		}
	}

	v[index]=1;
	int c1=count(v,next,left+1,right);
	v[index]=2;
	int c2=count(v,next,left,right+1);
	return c1+c2;
}

int main(){
	ios_base::sync_with_stdio(false); 
    lg d,k;
    cin>>d;

    fr(i,0,d){
    	cin>>n>>k;
    	vector<int> v;
    	int t;

    	fr(j,0,2*n){
    		v.push_back(0);
    	}

    	fr(j,0,k){
    		cin>>t;
    		v[t-1]=1;
    	}

    	int index=-1;
		int left=0,right=0;

		fr(j,0,2*n){
			if(v[j]==0){
				index=j;
				break;
			}else if(v[j]==1){
				left++;
			}else{
				right++;
			}
		}

    	cout<<count(v,index,left,right)<<endl;
    }

    return 0;
}

