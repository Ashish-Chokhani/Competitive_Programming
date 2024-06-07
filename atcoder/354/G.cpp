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

template<int SZ> struct Dinic {
	#define sz(x) ((int)x.size())
	int N,s,t;
	typedef ll F;
	struct Edge { int to, rev; F flo, cap; };
	vector<Edge> adj[SZ];
	void ae(int u, int v, F cap, F rcap = 0) { 
		assert(min(cap,rcap) >= 0); 
		Edge a{v,sz(adj[v]),0,cap}, b{u,sz(adj[u]),0,rcap};
		adj[u].push_back(a), adj[v].push_back(b); } 
	int lev[SZ]; typename vector<Edge>::iterator cur[SZ]; 
	bool bfs() {
		for (ll i = 0; i < N; i++) lev[i] = -1, cur[i] = begin(adj[i]);
		queue<int> q({s}); lev[s] = 0; 
		while (sz(q)) {
			int u = q.front(); q.pop();
			for(auto e: adj[u]) if (lev[e.to] < 0 && e.flo < e.cap) 
				q.push(e.to), lev[e.to] = lev[u]+1;
		}
		return lev[t] >= 0;
	}
	F dfs(int v, F flo) {
		if (v == t) return flo;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& e = *cur[v];
			if (lev[e.to]!=lev[v]+1||e.flo==e.cap) continue;
			F df = dfs(e.to,min(flo,e.cap-e.flo));
			if (df) { e.flo += df; adj[e.to][e.rev].flo -= df;
				return df; }
		}
		return 0;
	}
	F maxFlow(int NN, int ss, int tt) {
		N = NN, s = ss, t = tt; assert(s != t);
		F tot = 0; while (bfs()) while (F df = 
			dfs(s,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

ll kk[10] = {
  89, 
  101, 
  189,
  94,
  621,
  (ll)rng() % 1000 + 1051,
  (ll)rng() % 2000 + 2761,
  (ll)rng() % 4000 + 4441,
  (ll)rng() % 8000 + 8111,
  (ll)rng() % 16000 + 18883
};

ll primes[10] = {
  1000000001020030457,
  735632791,
  776531419,
  797003413,
  1062599999,
  1047899999,
  1031999999, 
  1027799999,
  1018199999,
  1000000007
};

struct string_hash {
  int len;
  ll mod, poly, inv;
  vector<ll> prefix,suffix;
  vector<ll> invs;
  
  void init(int n, string s, ll k = 89, ll m = primes[1]) {
    mod = m;
    poly = k;
    prefix = vector<ll>(n);
    suffix = vector<ll>(n);
    invs = vector<ll>(n);

    invs[0] = 1;
    inv = minv(k);
    for (int i = 1; i < n; i++) {
      invs[i] = (invs[i - 1] * inv) % mod;
    }

    ll x = 1;
    prefix[0] = (s[0] - '0' + 1);
    for (int i = 1; i < n; i++) {
      x = (x * k) % mod;
      prefix[i] = (prefix[i - 1] + x * (s[i] - '0' + 1)) % mod;
    }
    
    x=1;
    suffix[n-1] = (s[n-1] - '0' + 1);
    for (int i = n-2; i >= 0; i--) {
        x = (x * k) % mod;
        suffix[i] = (suffix[i + 1] + x * (s[i] - '0' + 1)) % mod;
    }

    len = n;
  }

  void extend(string next) {
    int x = next.length();
    for (int i = 0; i < x; i++) {
      invs.push_back((invs[i + len - 1] * inv) % mod);
    }

    ll p = mpow(poly, len - 1);
    for (int i = 0; i < x; i++) {
      p = (p * poly) % mod;
      prefix.push_back((prefix[i + len - 1] + p * (next[i] - '0' + 1)) % mod);
    }

    len += x;
  }
  
  void kill(int sz) { // remove last [sz] characters
	  for (int i = 0; i < sz; i++) {
		  invs.pop_back();
		  prefix.pop_back();
	  }
	  
	  len -= sz;
  }

  ll get_hash_prefix(int left, int right) {
    if (left == 0) return prefix[right];
    return ((prefix[right] - prefix[left - 1] + mod) * invs[left]) % mod;
  }
    
  ll get_hash_suffix(int left, int right) {
    if (right == len-1) return suffix[left];
    return ((suffix[left] - suffix[right + 1] + mod) * invs[len-right-1]) % mod;
  }
    
  //To check if a substring is palindrome or not, compare prefix hash with suffix hash

  ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
      if (exp % 2 == 1) {
          res = (res * base) % mod;
      }
      exp >>= 1;
      base = (base * base) % mod;
    }
    return res;
  }
  ll minv(ll base) {
    return mpow(base, mod - 2);
  }
};

template<int K>
struct multihash {
  string_hash sh[K];

  void init(int n, string s) {
    for (int i = 0; i < K; i++) {
      sh[i].init(n, s, kk[9 - i], primes[9 - i]);
    }
  }
  
  void extend(string s) {
	  for (int i = 0; i < K; i++) {
		sh[i].extend(s);
	  }
  }
  
  void kill(int x) {
	  for (int i = 0; i < K; i++) {
		sh[i].kill(x);
	  }
  }

  vector<ll> get_hash(int l, int r) {
    vector<ll> ret(K);
    for (int i = 0; i < K; i++) {
      ret[i] = sh[i].get_hash(l, r);
    }
    return ret;
  }

  bool compare(vector<ll> a, vector<ll> b) {
    for (int i = 0; i < K; i++) {
      if (a[i] != b[i]) return 0;
    }
    return 1;
  }
};

void solve(){
	int N;
	cin>>N;
	vector<string>S(N);
	for(int i=0;i<N;i++) cin>>S[i];
	vector<int>A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    map<string,int>vis;
    for(int i=0;i<N;i++) vis[S[i]]=max(vis[S[i]],A[i]);
    S.clear();
    A.clear();
    for(auto it:vis){
    	S.push_back(it.first);
    	A.push_back(it.second);
    }
    N=S.size();
    auto isSubstring=[&](int i,int j)->bool{
    	string s=S[i],t=S[j];
    	int l1=s.length(),l2=t.length();
    	if(l1>l2) return false;
    	string_hash sh[2];
        sh[0].init(l1,s);
        sh[1].init(l2,t);
    	for(int i=0;i+l1-1<l2;i++){
    		if(sh[0].get_hash_prefix(0,l1-1)==sh[1].get_hash_prefix(i,i+l1-1)) return true;
    	}
    	return false;
    };
    const int sz=203;
    Dinic<sz>g;
    int val=0;
    int source = 2 * N, sink = 2 * N + 1;
    for (int i = 0; i < N; ++i) {
        g.ae(source, i, A[i]);
        g.ae(i + N, sink, A[i]);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
        	if(i==j || !isSubstring(i,j)) continue;
        	g.ae(i, j + N, INF);
        }
    }
    const ll flow = g.maxFlow(sz,source, sink);
    const ll sum = accumulate(A.begin(), A.end(), 0LL);
    cout << sum - flow << endl;
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