#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define rfr(i,a,b) for(long long i = (long long)(a); i >= (long long)(b); i--)
#define mkp(i,j) make_pair(i,j)
#define MOD 1000000007
#define INF LONG_MAX
typedef long long lg;
typedef pair<lg,lg> pii;

lg s1,s2,n;
map<string,lg> mp;

lg run(lg current,lg p,lg q,lg b1,lg b2,lg till,string yy){
	cout<<"# "<<current<<" p:"<<p<<" q:"<<q<<" b1:"<<b1<<" b2:"<<b2<<" till:"<<till;
	cout<<" "<< yy<<endl;

	if(b1<=0 && b2<=0){
		cout<<"N: "<<n<<endl;
		if(till>=n){

			cout<<"yo1\n";
			// if(mp[yy]==1){
			// 	return 0;
			// }else{
			// 	mp[yy]=1;	
			// }
			
			return 1;
		}else{
			cout<<"yo2\n";
			return 0;
		}
	}	

	if(till>=n && b2>=0 && b1>=0 && p>=0 && q>=0){
		cout<<"yo3\n";
		// if(mp[yy]==1){
		// 	return 0;
		// }else{
		// 	mp[yy]=1;	
		// }
		
		return 1;
	}else if(p<0 || q<0 || b1<0 || b2<0 || till>n){
		return 0;
	}

	lg total=0,sn;

	if(current==1){
		sn=min(s1,p);
		// cout<<"sn1 "<<sn<<endl;
		fr(i,1,sn+1){
			total=total+run(2,p-i,q,b1-1,b2,till+i,yy+"1");
		}

	}else{
		
		sn=min(s2,q);
		// cout<<"sn2 "<<sn<<endl;
		fr(i,1,sn+1){
			total=total+run(1,p,q-i,b1,b2-1,till+i,yy+"2");
		}		
	}

	return total;
}

int main(){
    ios_base::sync_with_stdio(false); 
	lg t,m,p,q,b1,b2;

    cin>>t;

    fr(i,0,t){
    	cin>>p>>q>>n;
    	cin>>b1>>b2;
    	cin>>s1>>s2;
    	mp.clear();

    	lg t1=run(1,p,q,b1,b2,0,"");

    	cout<<"t1 "<<t1<<endl<<endl;
    	lg t2=run(2,p,q,b1,b2,0,"");
    	cout<<"t2 "<<t2<<endl;

    	lg total=t1+t2;
    	cout<<"ANS: "<<total<<endl<<endl;
    }

    return 0;
}

