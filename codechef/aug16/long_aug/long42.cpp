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
     
    		lg count[n+1];
     
    		for(j=0;j<=n;j++){
    			count[j]=0;
    			colors[j]=0;
    		}
     
    		for(j=0;j<m;j++){
    			
    			lg t1,t2;
    			scanf("%lld%lld",&t1,&t2);
     
    			rel[t1][t2]=1;
    			rel[t2][t1]=1;
    		}
     
    		//now forming reverse graph

    		for(j=1;j<=n;j++){
    			for(k=1;k<=n;k++){
    				if(rel[j][k]==0){
    					
    					if(j!=k){
                            arr[j].push_back(k);
                        }
    			
    				}
    			}
    		}

            /*for(j=1;j<=n;j++){
                cout<<"for "<<j<<" : ";
                for(k=0;k<arr[j].size();k++){
                    cout<<arr[j][k]<<" ";
                }
                cout<<endl;
            }*/


            int special=0;
            int flag=0;

            
            for(j=1;j<=n;j++){
                if(colors[j]!=0){
                    continue;
                }

                flag=0;

                queue<int> q;
                q.push(j);

                colors[j]=1;
                //printf("pushed %lld\n",j );

                while(!q.empty()){

                    int poped=q.front();

                    //printf("poped %d\n",poped );

                    q.pop();

                    
         
                    flag=0;
         
                    int c_temp=colors[poped];
                    int len=arr[poped].size();
         
                    for(int j1=0;j1<len;j1++){
                        int t=arr[poped][j1];
                        //printf("connected %d %d\n",t,poped);
         
                        if(colors[t]==c_temp){
                            flag=1;
                            //printf("matched %d (%d) with %lld (%d) c_temp: %d\n",poped,colors[poped],t,colors[t],c_temp );
                            break;
         
                        }else if(colors[t]==0){
                            if(c_temp==1){
                                colors[t]=2;
                            }else{
                                colors[t]=1;
                            }
                        
                               //printf("pushed %d and set color %d\n",t ,colors[t]);
                               q.push(t);
                        }
         
                    }
         
                    if(flag==1){
                       // cout<<"break1 "<<endl;
                        break;
                    }
                }

                if(flag==1){
                    //cout<<"break2 "<<endl;
                    break;
                }
            }

            //cout<<flag<<"colors : ";
            /*for(j=1;j<=n;j++){
                printf("%d ",colors[j] );
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