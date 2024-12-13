struct Dinic {
    struct Edge {
        int to, rev;
        ll flo, cap;
    };

    int N, s, t;
    vector<vector<Edge>> adj;
    vector<int> lev;
    vector<vector<Edge>::iterator> cur;

    Dinic(int size) : N(size), adj(size), lev(size), cur(size) {}

    void ae(int u, int v, ll cap, ll rcap = 0) {
        Edge a = {v, (int)adj[v].size(), 0, cap};
        Edge b = {u, (int)adj[u].size(), 0, rcap};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    bool bfs() {
        fill(lev.begin(), lev.end(), -1);
        queue<int> q;
        q.push(s);
        lev[s] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (Edge& e : adj[u]) {
                if (lev[e.to] < 0 && e.flo < e.cap) {
                    lev[e.to] = lev[u] + 1;
                    q.push(e.to);
                }
            }
        }

        return lev[t] >= 0;
    }

    ll dfs(int v, ll flo) {
        if (v == t) return flo;

        for (; cur[v] != adj[v].end(); cur[v]++) {
            Edge& e = *cur[v];
            if (lev[e.to] != lev[v] + 1 || e.flo == e.cap) continue;

            ll df = dfs(e.to, min(flo, e.cap - e.flo));
            if (df > 0) {
                e.flo += df;
                adj[e.to][e.rev].flo -= df;
                return df;
            }
        }

        return 0;
    }

    ll maxFlow(int s_, int t_) {
        s = s_, t = t_;
        ll tot = 0;

        while (bfs()) {
            for (int i = 0; i < N; i++) cur[i] = adj[i].begin();
            while (ll df = dfs(s, numeric_limits<ll>::max())) tot += df;
        }

        return tot;
    }
};
