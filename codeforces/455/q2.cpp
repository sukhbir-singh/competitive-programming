#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
typedef long long lg;
typedef pair<lg,lg> pii;

lg ff(lg n){
	if(n==0) return 0;
	if(n==1) return 1;
	else if(n<1) return 0;
	return n+ff(n-2);
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;
    cin>>t;

    cout<<ff(t)<<endl;

    return 0;
}

