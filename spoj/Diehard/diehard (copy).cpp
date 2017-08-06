#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int diehard(int h,int a,int air){
    if(dp[h][a]!=-1){
        cout<<"111";
        return dp[h][a];
    }

    if(air){
        dp[h][a]=1+diehard(h+3,a+2,0);
        cout<<"222";
        return dp[h][a];
    }else{
        int maxi=max(diehard(h-20,a+5,1), diehard(h-5,a-10,1));
        if(maxi==0){            
            dp[h][a]=0;
            cout<<"333";
            return dp[h][a];
        }else{
            dp[h][a]=1+maxi;
            cout<<"444";
            return dp[h][a];
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--){
        int h,a;
        scanf("%d%d",&h,&a);

        for(int j=0;j<=h;j++){
            for(int k=0;k<=a;k++){
                if(j==0 || k==0){
                    dp[j][k]=0;
                }else{
                    dp[j][k]=-1;
                }
            }
        }

        printf("%d\n",diehard(h,a,1));
    }
    return 0;
}

