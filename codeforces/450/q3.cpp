#include <bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i = (int)(a); i < (int)(b); i++)

int main()
{
    ios_base::sync_with_stdio(false); 
    typedef long long lg;
    lg n;
    cin>>n;
    int arr[n];
    int mark[n];

    F(i,0,n){
    	cin>>arr[i];
    }

    int c=1;
    int s1=-1,s2=-1,max_m=0;
    int i=1,m=-1;

    int flag=0;
    int ans=0;

    while(i<n){
        if(arr[i-1]<arr[i]){
            mark[i]=0;
        }else{
            flag=1;
            mark[i]=1;
        }
        i++;
    }

    if(flag==0){ //no marks
        ans=arr[0];
        cout<<ans<<endl;
    }else{
        int pre=-1;
        int temp_sum=0;
        int max=0;
        int middle=arr[0];
        int last_m=0;

        F(i,0,n){
            
            if(mark[i]==0){
                temp_sum++;    
            }else{
                if(pre==-1){
                    pre=temp_sum;
                    temp_sum=0;
                    max=pre;
                }else{
                    if(pre+temp_sum>max){
                        max=pre+temp_sum;
                        middle=last_m;
                    }
                    pre=temp_sum;
                    temp_sum=0;
                }

                last_m=arr[i];
            }
        } 

        cout<<middle<<endl;       
    }

    return 0;
}

