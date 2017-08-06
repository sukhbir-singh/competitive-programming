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

    vector<int> v;

    F(i,0,n){
        inp(a[i]);
        inp(b[i]);
        inp(c[i]);
        inp(d[i]);
    }

    F(i,0,n){
        F(j,0,n){
            v.push_back(c[i]+d[j]);
        }
    }

    sort(v.begin(),v.end());

    int count=0,sum=0;
    
    F(i,0,n){
        F(j,0,n){
            sum=-(a[i]+b[j]);
            int lo=0,hi=v.size()-1,mid=0;

            while(lo<hi){
                mid=lo+(hi-lo)/2;

                if(v.at(mid)>=sum){
                    hi=mid;
                }else{
                    lo=mid+1;
                }
            }

            if(v.at(lo)!=sum){
                continue;
            }

            int l=0;
            hi=v.size()-1;

            while(l<hi){
                mid=l+(hi-l+1)/2;

                if(v.at(mid)<=sum){
                    l=mid;
                }else{
                    hi=mid-1;
                }
            }

            count+=l-lo+1;

        }
    }

    printf("%d\n",count);
    return 0;
}
