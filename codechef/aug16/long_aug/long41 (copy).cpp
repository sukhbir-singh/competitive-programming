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
     
    		int rel[n+1][n+1];
     
    		for(j=0;j<=n;j++){
    			for(k=0;k<=n;k++){
    				rel[j][k]=0;
    			}
    		}
     
    		lg count[n+1],parent[n+1];
     
    		for(j=0;j<=n;j++){
    			count[j]=0;
    			colors[j]=0;
    		}
     
    		for(j=0;j<m;j++){
    			
    			lg t1,t2;
    			scanf("%lld%lld",&t1,&t2);
     
    			rel[t1][t2]=1;
    			rel[t2][t1]=1;
     
    			//arr[t1].push_back(t2);
    			//arr[t2].push_back(t1);
     
    		}
     
    		//now forming reverse graph
     
    		int flag11=0;
     
    		for(j=1;j<=n;j++){
    			flag11=0;
     
    			for(k=1;k<=n;k++){
    				if(rel[j][k]==0){
    					
    					if(j!=k)
    					arr[j].push_back(k);
    			
    				}else{
    					flag11=1;
    				}
    			}
     
    			if(flag11==0){
    				//printf("for j== %lld,flag is %d\n",j,flag11 );
    				break;
    			}
    		}
     
    		int flag=0;

            for(int j1=1;j1<=n;j1++){

            if(colors[j1]!=0){
                continue;
            }

            flag=0;

    		queue<int> q;
    		q.push(j1);
     
    		if(flag11==1){
     
    		while(!q.empty()){
    			int poped=q.front();
    			q.pop();
     
    			if(colors[poped]==0){
    				colors[poped]=1;
    			}
     
    			flag=0;
     
    			int c_temp=colors[poped];
     
    			for(j=0;j<arr[poped].size();j++){
    				int t=arr[poped][j];
     
    				if(colors[t]==c_temp){
    					flag=1;
    					break;
     
    				}else if(colors[t]==0){
    					if(c_temp==1){
    						colors[t]=2;
    					}else{
    						colors[t]=1;
    					}
     
    					q.push(t);
     
    				}
     
    			}
     
    			if(flag==1){
                    //cout<<"break1 "<<endl;
    				break;
    			}
     
    		}


     
    		}else{//
                //cout<<"break2 "<<endl;
    			flag=1;
                break;
     
    		}

            if(flag==1){
                break;
            }

            }
     
    		/*cout<<"colors : ";
    		for(j=1;j<=n;j++){
    			cout<<colors[j]<<" ";
    		}
     
    		cout<<endl;
    		for(int j=1;j<=n;j++){
    			for(int i1=0; i1<arr[j].size(); ++i1)
      				cout <<arr[j][i1] << ' ';
    			
    			printf("\n");
    		}*/
    		
    		if(flag==0){
    			printf("YES\n");
    		}else{
    			printf("NO\n");
    		}
     
    	}
     
    	return 0;
    }
     
     
    /*
    3
    3 2
    1 2
    2 3
    4 3
    1 2
    2 3
    2 4
    6 7
    1 2
    1 3
    2 3
    2 4
    4 5
    4 6
    5 6
    */ 