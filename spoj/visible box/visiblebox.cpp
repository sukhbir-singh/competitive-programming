#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rfr(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)

int main(int argc, char const *argv[]){
	typedef long long lg;
    ios_base::sync_with_stdio(false); 

	lg t,n;
	cin>>t;

	fr(i,0,t){
		cin>>n;

		lg arr[n];
		fr(j,0,n){
			cin>>arr[j];
		}

		sort(arr,arr+n);
		lg ans=0,max_heap=n-1;

		rfr(j,n-1,0){
			if(j==n-1){
				ans+=1;
				continue;
			}

			if(arr[max_heap]>=2*arr[j]){
				max_heap--;

				if(max_heap<0){
					break;
				}
			}else{
				ans+=1;
			}
		}

		cout<<"Case "<<i+1<<": "<<ans<<endl;
	}

	return 0;
}