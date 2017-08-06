#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

int main()
{
    int n;
    scanf("%d",&n);

    int a[n],b[n],c[n],d[n];

    F(i,0,n){
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }

    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    sort(d,d+n);

    int count=0;
    
    F(i,0,n){
        F(j,0,n){
            F(k,0,n){
                int sum=a[i]+b[j]+c[k];

                if(sum>-d[0]){
                    break;
                }

                if(binary_search(d,d+n,-sum)){
                    count++;

                    cout<<a[i]<<","<<b[j]<<","<<c[k]<<","<<-sum<<endl;
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
