#include <bits/stdc++.h>
using namespace std;

struct lca_lift {
  const int lg = 18;
  int n;
  vector<int> depth;
  vector<int> parent;
  vector<vector<int> > edges;
  vector<vector<int> > lift;
  
  void init(int sz) {
    n = sz;
    depth = vector<int>(n);
    parent=vector<int>(n);
    edges = vector<vector<int> >(n, vector<int>());
    lift = vector<vector<int> >(n, vector<int>(lg, -1));
  }

  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  void attach(int node_to_attach, int node_to_attach_to) {
    int a = node_to_attach, b = node_to_attach_to;
    edge(a, b);

    lift[a][0] = b;

    for (int i = 1; i < lg; i++) {
      if (lift[a][i - 1] == -1) lift[a][i] = -1;
      else lift[a][i] = lift[lift[a][i - 1]][i - 1];
    }

    depth[a] = depth[b] + 1;
  }

  void init_lift(int v = 0) {
    depth[v] = 0;
    dfs(v, -1);
  }

  void dfs(int v, int par) {
    lift[v][0] = par;
    parent[v]=par;
    for (int i = 1; i < lg; i++) {
      if (lift[v][i - 1] == -1) lift[v][i] = -1;
      else lift[v][i] = lift[lift[v][i - 1]][i - 1];
    }

    for (int x: edges[v]) {
      if (x != par) {
        depth[x] = depth[v] + 1;
        dfs(x, v);
      }
    }
  }

  int get(int v, int k) {
    for (int i = lg - 1; i >= 0; i--) {
      if (v == -1) return v;
      if ((1 << i) <= k) {
        v = lift[v][i];
        k -= (1 << i);
      }
    }
    return v;
  }

  int get_lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    int v = get(a, d);
    if (v == b) {
      return v;
    } else {
      for (int i = lg - 1; i >= 0; i--) {
        if (lift[v][i] != lift[b][i]) {
          v = lift[v][i];
          b = lift[b][i];
        }
      }
      return lift[b][0];
    }
  }
  
  int get_dist(int a, int b) {
      int v = get_lca(a, b);
      return depth[a] + depth[b] - 2 * depth[v];
  }
};

int main() {
    int n,q;
    cin >> n >>q;
    lca_lift lca;
    lca.init(n);
    for(int i = 0; i < n-1; ++i) {
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        lca.edge(u,v);
    }
    lca.dfs(0,-1);
    for(int i = 0; i < q; i++) {
        int k;
        cin>>k;
        vector<int>arr(k);
        for(int j=0;j<k;j++){
            cin>>arr[j];
            --arr[j];
        }
        int left=-1,maxi_depth=-1;
        for(int j=0;j<k;j++){
            if(lca.depth[arr[j]]>maxi_depth)
            {
                maxi_depth=lca.depth[arr[j]];
                left=arr[j];
            }
        }
        int flag=0;
        for(int j=0;j<k;j++){
            if(arr[j]==0)
            continue;
            if(lca.get_lca(lca.parent[arr[j]],left)!=lca.parent[arr[j]]){
                cout<<"NO\n";
                flag=1;
                break;
            }
        }
        if(flag)
        continue;
        cout<<"YES\n";
    }
}
