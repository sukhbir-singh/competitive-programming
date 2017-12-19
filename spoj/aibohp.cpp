#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)

int longest_sequence(string a){
    int l1=a.length();

    int arr[l1+1][l1+1];

    fr(i,0,l1+1){
        fr(j,0,l1+1){
            if(i==0 || j==0){
                arr[i][j]=0;
            }else{
                if(a[i-1]==a[l1-j]){
                    arr[i][j]=arr[i-1][j-1]+1;
                }else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
    }

    return arr[l1][l1];
}

int main()
{
    ios_base::sync_with_stdio(false); 
    string s;

    typedef long long lg;
    lg n,m;
    cin>>n;

    fr(i,0,n){
    	cin>>s;
        int longest=longest_sequence(s);
        cout<<s.length()-longest<<endl;
    }

    return 0;
}

