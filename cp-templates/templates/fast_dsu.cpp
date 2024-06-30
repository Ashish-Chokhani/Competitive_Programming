namespace fast_dsu {
    vector<int>dsu_par,dsu_sz;

    void init(int n) {
        dsu_par.resize(n);
        dsu_sz.resize(n);
        for (int i = 0; i < n; i++){
          dsu_par[i] = i;
          dsu_sz[i]=-1;
        }
    }

    int find(int v) {
        while ((v = dsu_par[v]) != dsu_par[v]);
        return v;
    }

    bool connected(int v, int u) {
        return find(v) == find(u);
    }

    void merge(int v, int u) {
        int par_u=find(u),par_v=find(v);
        if (dsu_sz[par_v] > dsu_sz[par_u]) swap(par_u,par_v);
        dsu_par[par_u] = par_v;
        dsu_sz[par_v] += dsu_sz[par_u];
    }
}

using namespace fast_dsu;