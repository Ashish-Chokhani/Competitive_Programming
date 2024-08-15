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

int queries_made_no = 0;
bool ask(int u) {
  cout << "? " << u << endl;
  bool yes;
  cin >> yes;
  queries_made_no += !yes;
  return yes;
}
void answer(int u) {
  cout << "! " << u << endl;
}

void solve(){
  queries_made_no = 0;
  
  int n;
  cin >> n;
  
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  int leaf = 0;
  vector<int> max_depth(n + 1);
  auto dfs = [&](auto &self, int u, int p) -> void {
    if (u != 1 && (int)adj[u].size() == 1) {
      leaf = u;
    }
    
    max_depth[u] = 1;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      self(self, v, u);
      max_depth[u] = max(max_depth[u], max_depth[v] + 1);
    }
  };
  dfs(dfs, 1, 0);
  
  vector<int> path;
  auto make_path = [&](auto &self, int u, int p) -> void {
    path.pb(u);
    
    vector<int> good;
    for (int v : adj[u]) {
      if (v == p) {
        continue;
      }
      
      if (max_depth[v] >= S) {
        good.pb(v);
      }
    }
    
    if ((int)good.size() == 1) { // oops
      self(self, good[0], u);
      return;
    }
    for (int v : good) {
      if (ask(v)) {
        self(self, v, u);
        break;
      }
    }
  };
  make_path(make_path, 1, 0);
  
  if (ask(leaf)) {
    answer(leaf);
    return;
  }
  while (queries_made_no < S + 10) {
    ask(leaf);
  }
  
  int k = path.size();
  int st = 0, dr = k - 1;
  while (st < dr) {
    int mid = (st + dr + 1) / 2;
    
    if (ask(path[mid])) {
      st = mid;
    } else {
      dr = max(mid - 2, 0);
      st = max(st - 1, 0);
    }
  }
  
  answer(path[st]);
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