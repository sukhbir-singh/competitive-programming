#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

int main()
{
    int n;
    scanf("%d",&n);

    int a[n],b[n],c[n],d[n];

    map<int,int> mp;

    F(i,0,n){
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
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

    printf("%d\n", count);

    return 0;
}
