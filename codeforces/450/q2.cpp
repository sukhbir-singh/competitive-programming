#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

int main()
{
    ios_base::sync_with_stdio(false); 
    typedef long long lg;
    lg a,b,c;
    cin>>a>>b>>c;

    double d=a*1.0/b-a/b;
    int count=0,flag=0;

    F(i,0,3000){
        count++;

        a=a*10.0;
        d=a*1.0/b;

        // cout<<">> "<<d<<endl;
        if((int)(d)%10==c){
            flag=1;
            break;
        }

        d=d-(int)d;
        a=a%b;

        // cout<<"d2 "<<d<<endl<<endl;
    }

    if(flag==0){
        cout<<-1<<endl;
    }else{
        cout<<count<<endl;
    }

    return 0;
}

