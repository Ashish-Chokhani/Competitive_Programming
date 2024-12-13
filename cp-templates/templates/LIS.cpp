vector<int>dp(N+1,INF),id(N+1,-1),par(N+1,-1);
dp[0]=arr[0]; id[0]=0;
int len=N-1;
    for(int i=1;i<N;i++){
    	int idx=upper_bound(all(dp),arr[i])-dp.begin();
    	dp[idx]=arr[i];
    	id[idx]=i;
    	par[i]=idx?id[idx-1]:-1;
    }
    
    while(id[len]==-1) len--;
