#include <bits/stdc++.h>
using namespace std;

int dp[1007][1007][1];

int diehard(int h,int a,int air){
    if(h<=0 || a<=0){
        return 0;
    }

    if(dp[h][a][air]!=-1){
        return dp[h][a][air];
    }

    if(air){
        dp[h][a][air]=1+diehard(h+3,a+2,0);
        return dp[h][a][air];
    }else{
        int maxi=max(diehard(h-20,a+5,1), diehard(h-5,a-10,1));
        if(maxi==0){            
            dp[h][a][air]=0;
            return dp[h][a][air];
        }else{
            dp[h][a][air]=1+maxi;
            return dp[h][a][air];
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int j=0;j<=1006;j++){
        for(int k=0;k<=1006;k++){
            if(j==0 || k==0){
                dp[j][k][0]=0;
                dp[j][k][1]=0;
            }else{
                dp[j][k][0]=-1;
                dp[j][k][1]=-1;
            }
        }
    }

    while(t--){
        int h,a;
        scanf("%d%d",&h,&a);

        printf("%d\n",diehard(h,a,1));
    }
    return 0;
}

