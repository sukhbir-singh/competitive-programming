#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    typedef long long lg;
    lg times,i,j,k,p,n,m;
    scanf("%lld",&times);
    
    for(i=0;i<times;i++){
 
        scanf("%lld%lld",&n,&m);
 
        vector<int> arr[n+1];
        int colors[n+1];
 
        for(j=0;j<=n;j++){
            colors[j]=0;
        }
 
        for(j=0;j<m;j++){
            
            lg t1,t2;
            scanf("%lld%lld",&t1,&t2);
 
            arr[t1].push_back(t2);
            arr[t2].push_back(t1);
        }

       /* for(j=1;j<=n;j++){
            cout<<"for "<<j<<" : ";
            for(k=0;k<arr[j].size();k++){
                cout<<arr[j][k]<<" ";
            }
            cout<<endl;
        }*/

        int flag=0;

        for(j=1;j<=n;j++){

            if(colors[j]==0){
                colors[j]=1;
            }

            queue<int> q;
            q.push(j);

            while(!q.empty()){
                int temp=q.front();
                q.pop();

                int sz=arr[temp].size();

                for(k=0;k<sz;k++){
                    if(colors[arr[temp][k]]==colors[temp]){
                        flag=1;
                        break;
                    }else{
                        if(colors[temp]==1){
                            colors[arr[temp][k]]=2;
                        }else{
                            colors[arr[temp][k]]=1;
                        }
                    }
                }

                if(flag==1){
                    break;
                }

            }

            if(flag==1){
                break;
            }

        }

        printf("Scenario #%lld:\n",i+1 );

        if(flag==0){
            printf("No suspicious bugs found!\n");
        }else{
            printf("Suspicious bugs found!\n");
        }
 
    }
 
    return 0;
}