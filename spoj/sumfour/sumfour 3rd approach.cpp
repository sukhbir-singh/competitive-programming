#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

inline void inp(int &n){
   n=0;
   int ch=getchar_unlocked();
   int sign=1;
   while(ch<'0'||ch>'9'){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch>='0'&&ch<='9')
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

int main()
{
    int n;
    inp(n);

    int a[n],b[n],c[n],d[n];

    unordered_map <int, int> mp;
    mp.reserve(16000000);

    F(i,0,n){
        inp(a[i]);
        inp(b[i]);
        inp(c[i]);
        inp(d[i]);
    }

    F(i,0,n){
        F(j,0,n){
            mp[c[i]+d[j]]=mp[c[i]+d[j]]+1;
        }
    }

    int count=0;
    
    F(i,0,n){
        F(j,0,n){
            int sum=a[i]+b[j];

            if(mp[-sum]>0){
                count=count+mp[-sum];
            }
        }
    }

    cout<<count<<endl;

    return 0;
}
