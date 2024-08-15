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
  int n,leaf=-1;
  cin>>n;
  vector<int>adj[n];
  int no_queries=0;
  for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    --u;--v;
    adj[u].push_back(v); adj[v].push_back(u);
  }
  auto query=[&](int x){
    cout<<"? "<<x+1<<"\n";
    cout.flush();
    int t; cin>>t;
    no_queries+=1-t;
    return t;
  };
  auto answer=[&](int x){
    cout<<"! "<<x+1<<"\n";
    cout.flush();
  };
  vector<int>dp(n),path;
  const int S=70;
  function<void(int,int)>DFS=[&](int u,int p){
    dp[u]=1;
    for(int v:adj[u]){
      if(v==p) continue;
      DFS(v,u); 
      dp[u]=max(dp[u],1+dp[v]);
    }
    if(dp[u]==1) leaf=u;
  };  
  DFS(0,-1);
  if(query(leaf)){
    answer(leaf); return;
  }
  for(int i=1;i<=S;i++) int t=query(leaf);
  function<void(int,int)>make_path=[&](int u,int p){
    path.push_back(u);
    vector<int>good;
    for(int v:adj[u]){
      if(v==p) continue;
      if(dp[v]>=S) good.push_back(v);
    }
    if(good.size()==1){
      make_path(good.back(),u);
      return;
    }
    for(int v:good){
      if(query(v)){
        make_path(v,u);
        break;
      }
    }
  };  
  make_path(0,-1);
  int k=path.size(),ans=0;
  int l=0,r=k-1;
  while(l<r){
    int mid=(l+r+1)>>1 ;
    if(query(path[mid])) l=mid;
    else{
      l=max(0LL,l-1);
      r=max(0LL,mid-2);
    }
  }
  answer(path[l]);
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
    cin >> t; 
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