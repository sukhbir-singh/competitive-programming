#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
#define NINF LONG_MIN
typedef long long lg;
typedef pair<lg,lg> pii;
int add(int x,int y){int res=(x+0LL+y)%MOD;return (res<0)?res+MOD:res;}
 
int sieve_len=1000005;
bool sieve[1000005];
 
lg ary[10000000]={0};

int main(){
    ios_base::sync_with_stdio(false); 
    lg n;
    cin>>n;    
 
    for(int i=2; i<sieve_len; i++){
        sieve[i]=true;
    }
 
    sieve[0]=false;
    sieve[1]=false;
    sieve[2]=true;
 
    for(int i=2; i*i<sieve_len; i++){
        if(sieve[i]){
            for(int j=2;i*j<sieve_len;j++){
                sieve[i*j]=false;
            }
        }
    }
 
    vector<int> primes;
    for(int i=1;i<sieve_len;i++){
        if(sieve[i]){
            primes.push_back(i*i);
        } 
    }
 
    lg sz=primes.size();
    
    //pre computed array
    lg array[100]={255051, 510100, 765150, 1020240, 1275255, 1530324, 1785396, 2040498, 2295460, 2550519, 2805570, 3060636, 3315717, 3570752, 3825848, 4080924, 4335960, 4591004, 4846056, 5101110, 5356150, 5611175, 5866252, 6121305, 6376347, 6631424, 6886496, 7141544, 7396572, 7651611, 7906665, 8161725, 8416768, 8671824, 8926869, 9181948, 9437048, 9692125, 9947188, 10202274, 10457284, 10712320, 10967427, 11222420, 11477475, 11732526, 11987596, 12242668, 12497692, 12752716, 13007826, 13262840, 13517919, 13772964, 14027994, 14283068, 14538112, 14793200, 15048180, 15303240, 15558250, 15813316, 16068366, 16323444, 16578496, 16833537, 17088568, 17343621, 17598708, 17853764, 18108804, 18363807, 18618950, 18874040, 19129080, 19384184, 19639244, 19894312, 20149407, 20404432, 20659520, 20914551, 21169636, 21424644, 21679686, 21934759, 22189800, 22444828, 22699875, 22954905, 23209974, 23465025, 23720165, 23975190, 24230240, 24485265, 24740316, 24995348, 25250425, 25505464};
    
    lg range_index=n/100000;
    lg upper=array[range_index],lower=2;

    if(range_index>0){
        lower=array[range_index-1];
    }

    lg count=(range_index==0)?0:100000*range_index-1;
    lg ans=-1;
    lg i=lower;    

    if(n%100000==0){
        ans=array[range_index-1];
    }

    // cout<<"lower: "<<lower<<" upper: "<<upper<<" count: "<<count<<endl;

    while(1){
    	int flag=0;

        if(ans!=-1){
            break;
        }

	    fr(j,0,sz){
	    	lg prime=primes[j];

            if(prime/2>i) break;

	    	 else if((i%prime)==0){
	    		flag=1;
	    		break;
	    	}
        }

	    if(flag==1){
	    	count++;        
	    }

	    if(count==n){
	    	ans=i;
	    	break;
	    }
        i++;
    }

    cout<<ans<<endl;

    return 0;
}

