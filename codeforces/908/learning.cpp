//lessons 
//how to generate next lexicographical permutation of a string
//how to arrange string characters for making least lexicographical sequence 
//how to generate all permutations of a string using stl

#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m;

    string s="RLUD";
    sort(begin(s),end(s));

    int c=1;
	cout<<c<<" "<<s<<endl;
	c++;

    while(next_permutation(s.begin(),s.end())){
    	cout<<c<<" "<<s<<endl;
    	c++;
    }

    return 0;
}

