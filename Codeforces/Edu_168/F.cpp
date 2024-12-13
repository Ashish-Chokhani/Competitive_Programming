#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) (x).begin(), (x).end()
#define int long long int
typedef long double lld;
typedef unsigned long long ull;
const int mod = 1000000007; //998244353
const int INF = 1e18;
using ll = long long;
// const lld pi = 3.14159265358979323846;
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxHeap = priority_queue<T>;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

#ifdef CLEVERFOX
    #define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
    #define eprintf(...) 42
#endif

//Usage:
//eprintf("--- Case #%d start ---\n", i);
//printf("Case #%d: ", i);
//solve();
//eprintf("--- Case #%d end ---\n", i);
//eprintf("time = %.5lf\n", getCurrentTime());
//eprintf("++++++++++++++++++++\n");

int seed = std::chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
// mt19937_64 rng(61378913);
/* usage - just do rng() */

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//Usage:
//unordered_map<long long, int, custom_hash> safe_map;
//gp_hash_table<long long, int, custom_hash> safe_hash_table;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>ordered_set;
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

int gcd(int a, int b) {
    if (a == 0)
        return b;
 
    return gcd(b % a, a);
}

int floor_div(int x, int y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x >= 0) return x / y;
    return (x + 1) / y - 1;
}

int ceil_div(int x, int y) {
    assert(y != 0);
    if (y < 0) {
        y = -y;
        x = -x;
    }
    if (x <= 0) return x / y;
    return (x - 1) / y + 1;
}

void solve(){
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>>adj[N],G[N];
    vector<array<int,3>>edges;
    for(int i=0;i<M;i++){
        int u,v,wt;
        cin>>u>>v>>wt; --u; --v;
        adj[u].push_back({v,wt}); adj[v].push_back({u,wt});
        edges.push_back({u,v,wt});
    }
    auto dijstra=[&](int src){
        vector<int>dist(N,INF);
        dist[src]=0;
        minHeap<pair<int,int>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if(d!=dist[u]) continue;
            for(auto [v,wt]:adj[u]){
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    };
    vector<int>d1=dijstra(0),dn=dijstra(N-1);
    int i=-1;
    for(auto [u,v,wt]:edges){
        i++;
        if(d1[u]+wt+dn[v]==d1[N-1] || d1[v]+wt+dn[u]==d1[N-1]){
            G[u].push_back({v,i});
            G[v].push_back({u,i});
        }
    }
    vector<int>ans(M);
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
        for(int i=0;i<N;i++) if(!vis[i]) DFS(i,-1);
    };
    bridge();
    for(int i=0;i<M;i++) cout<<(ans[i]?"Yes\n":"No\n");
} 

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifdef CLEVERFOX
    auto begin = std::chrono::high_resolution_clock::now();
    #endif
    
    #ifdef CLEVERFOX
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    
    int t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    
    #ifdef CLEVERFOX
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4)<<fixed;
    cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
    return 0;
}