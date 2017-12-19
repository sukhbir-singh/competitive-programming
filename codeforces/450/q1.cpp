#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

int main()
{
    ios_base::sync_with_stdio(false); 
    typedef long long lg;
    lg n,x,y,m1=0,m2=0;
    cin>>n;

    F(i,0,n){
    	cin>>x>>y;

        if(x>0){
            m1++;
        }else{
            m2++;
        }
    }

    if(m1<=1 || m2<=1){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}

