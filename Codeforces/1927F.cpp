#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e9+8;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>ordered_set;
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

class DSU
{
    vector<int> parent, size, rank,lightest_edge;
public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
            lightest_edge.push_back(INF);
        }
    }

public:
    int findPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findPar(parent[node]);
    }

public:
    bool isSameComponent(int u,int v)
    {
        return findPar(u)==findPar(v);
    }

public:
    void unionByRank(int u, int v)
    {
        int paru = findPar(u);
        int parv = findPar(v);
        if (paru == parv)
            return;
        else
        {
            if (rank[paru] < rank[parv])
            {
                parent[paru] = parv;
            }
            else if (rank[paru] > rank[parv])
            {
                parent[parv] = paru;
            }
            else if (rank[paru] == rank[parv])
            {
                parent[parv] = paru;
                rank[paru]++;
            }
        }
    }

public:
  void adjustWeight(int u,int wt){
    int paru= findPar(u);
    lightest_edge[paru]=min(lightest_edge[paru],wt);
  }
};

struct Edge
{
	ll u,v,wt;
	Edge(ll _u, ll _v, ll _wt) : u(_u), v(_v), wt(_wt) {}
};

bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.wt > e2.wt; // Sort in descending order based on weight
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<Edge>edges;
  for(ll i=0;i<m;i++){
  	ll u,v,wt;
  	cin>>u>>v>>wt;
  	--u;--v;
  	edges.emplace_back(u,v,wt);
  }
  DSU dsu(n);
  auto compareEdges=[&](const Edge& e1, const Edge& e2)->bool{
    return e1.wt > e2.wt; // Sort in descending order based on weight
  };
  ll ans=INF;
  sort(edges.begin(),edges.end(),compareEdges);
  for(const Edge &it:edges){
  	ll u=it.u;
  	ll v=it.v;
  	ll wt=it.wt<<endl;
  	if(dsu.isSameComponent(u,v)){
  		//Minimize answer
  		// Store starting node
  	}
  	else{
  		dsu.unionByRank(u,v);
  	}
  }
  cout<<ans<<endl;
  // Now print by DFS fdom starting node
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("error.txt","w",stderr);
    //#endif
    
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}