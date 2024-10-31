auto bridge=[&](){
        vector<int>tin(N),low(N,INF),vis(N);
        int timer=0;
        function<void(int,int)>DFS=[&](int u,int p){
            vis[u]=1;
            low[u]=tin[u]=timer++;
            for(auto [v,id]:G[u]){
                if(v==p) continue;
                if(!vis[v]) DFS(v,u);
                if(low[v]>tin[u]) ans[id]=1;
                low[u]=min(low[v],low[u]);
            }
        };
