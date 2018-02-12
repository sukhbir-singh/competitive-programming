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

void print(set<lg> s1,set<lg> s2,lg x,lg n){
	string s="";
	fr(i,1,n+1){
		if(i==x){
			s+="2";
		}else if(s1.count(i)){
			s+="0";
		}else{
			s+="1";
		}
	}
	cout<<s<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    lg t,n,m,x;
    cin>>t;
    string imp="impossible";

    fr(i,0,t){
    	cin>>x>>n;

    	lg total=n*(n+1)/2;
    	total-=x;

    	if(total%2==1){
    		cout<<imp<<endl;
    		continue;
    	}

    	set<lg> st1,st2;
    	lg s1=0,s2=0;
    	lg c=0;

    	fr(j,1,n+1){
    		if(j==x) continue;

    		if(c==0 || c==3){
    			s1+=j;
    			st1.insert(j);
    		}else{
    			s2+=j;
    			st2.insert(j);
    		}
    		c++;
            c=c%4;
    	}

        // processing after initial partition

    	if(s1==s2){
    		print(st1,st2,x,n);
    	}else{
    		if(s1>s2){
    			lg diff=s1-s2;
    			if(diff%2==1){
    				cout<<imp<<endl;
    				continue;
    			}

    			diff/=2;

                //p1
    			if(st1.count(diff)==1){
    				st1.erase(diff);
    				st2.insert(diff);
    				print(st1,st2,x,n);
    				continue;
    			}

                //p1.5
                lg size=st1.size(),temp;
                auto it=st1.begin();
                int flag=0;

                fr(j,0,size){
                    if(st2.count(*it-diff)){
                        st2.insert(*it);                        
                        st2.erase(*it-diff);
                        st1.insert(*it-diff);                        
                        st1.erase(*it);

                        print(st1,st2,x,n);
                        flag=1;
                        break;
                    }
                    it++;
                }

                if(flag==1){
                    continue;
                }

                //p2
                size=st1.size(),temp;
                it=st1.begin();
                auto it_temp=st1.begin(); //temp
                flag=0;

                fr(j,0,size-1){
                    it_temp=++it;
                    --it;

                    temp=*it+*it_temp;
                    temp=temp-diff;

                    if(temp==0){
                        st2.insert(*it);
                        st1.erase(*it);
                        st2.insert(*it_temp);
                        st1.erase(*it_temp);
                        print(st1,st2,x,n);
                        flag=1;
                        break;

                    }else if(temp>0){
                        if(st2.count(temp)){
                            st2.insert(*it);
                            st1.erase(*it);
                            st2.insert(*it_temp);
                            st1.erase(*it_temp);

                            st1.insert(temp);
                            st2.erase(temp);

                            print(st1,st2,x,n);
                            flag=1;
                            break;
                        }
                    }

                    it++;
                }

                if(flag==0){
                    cout<<imp<<endl;
                }
                continue;

    		}else{ // similiar but slightly different
    			lg diff=s2-s1;

    			if(diff%2==1){
                    cout<<imp<<endl;
                    continue;
                }

                diff/=2;

                //p1
                if(st2.count(diff)==1){
                    st1.insert(diff);
                    st2.erase(diff);
                    print(st1,st2,x,n);
                    continue;
                }

                //p1.5
                lg size=st2.size(),temp;
                auto it=st2.begin();
                int flag=0;

                fr(j,0,size){
                    if(st1.count(*it-diff)){
                        st1.insert(*it);                        
                        st1.erase(*it-diff);
                        st2.insert(*it-diff);                        
                        st2.erase(*it);

                        print(st1,st2,x,n);
                        flag=1;
                        break;
                    }
                    it++;
                }

                if(flag==1){
                    continue;
                }

                //p2
                size=st2.size(),temp;
                it=st2.begin();
                auto it_temp=st2.begin();
                flag=0;

                fr(j,0,size-1){
                    it_temp=++it;
                    --it;

                    temp=*it+*it_temp;
                    temp=temp-diff;

                    if(temp==0){
                        st1.insert(*it);
                        st2.erase(*it);
                        st1.insert(*it_temp);
                        st2.erase(*it_temp);
                        print(st1,st2,x,n);
                        flag=1;
                        break;

                    }else if(temp>0){
                        if(st1.count(temp)){
                            st1.insert(*it);
                            st2.erase(*it);
                            st1.insert(*it_temp);
                            st2.erase(*it_temp);

                            st2.insert(temp);
                            st1.erase(temp);

                            print(st1,st2,x,n);
                            flag=1;
                            break;
                        }
                    }

                    it++;
                }

                if(flag==0){
                    cout<<imp<<endl;
                }
                continue;

    		}
    	}
    }

    return 0;
}

