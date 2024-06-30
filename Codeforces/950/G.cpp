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

struct node {
  node* ch[2];
  int cnt;

  node() {
    cnt = 0;
    ch[0] = nullptr;
    ch[1] = nullptr;
  }

  node* next(int b) {
    if (!ch[b]) ch[b] = new node;
    return ch[b];
  }
};

class Trie{
private:
	node* root;
	
public:
	Trie(){
		root=new node();
	}
	
	void ins(int x) {
	  node* targ = root;
	  for (int i = 29; i >= 0; --i) {
	    int v = !!(x & (1 << i));
	    targ = targ->next(v);
	    ++targ->cnt;
	  }
	}

	void del(int x) {
	  node* targ = root;
	  for (int i = 29; i >= 0; --i) {
	    int v = !!(x & (1 << i));
	    targ = targ->next(v);
	    --targ->cnt;
	  }
	}

	int best(int x) {
	  node* targ = root;
	  int ans = 0;
	  for (int i = 29; i >= 0; --i) {
	    int v =1-!!(x & (1 << i));
	    if (targ->next(v)->cnt > 0) {
	      targ = targ->next(v);
	      ans += (v << i);
	    } else {
	      targ = targ->next(!v);
	      ans += ((1-v) << i);
	    }
	  }
      return ans;
    }
};

void solve(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n];
	for(int i=0;i<n-1;i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		--u;--v;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}
	vector<int>depth(n,0),d(n);
	function<void(int,int)>DFS=[&](int u,int p){
		if(p!=-1) depth[u]=1+depth[p];
	    for(auto it:adj[u]){
	    	int v=it.first,wt=it.second;
	    	if(v==p) continue;
	    	d[v]=d[u]^wt;
	    	DFS(v,u);
	    }	
	};
	DFS(0,-1);
	Trie T[2];
	for(int i=0;i<n;i++){
		int v=depth[i]&1;
		T[v].ins(d[i]);
	}
	int cur=0;
	while(m--){
		char ch;
		cin>>ch;
		if(ch=='^'){
			int y;
			cin>>y;
			cur^=y;
		}
		else{
			int v,x;
			cin>>v>>x;
			--v;
			T[depth[v]&1].del(d[v]);
			int ans=0;
			ans=max(ans,d[v]^x^(T[depth[v]&1].best(d[v]^x)));
			T[depth[v]&1].ins(d[v]);
			ans=max(ans,d[v]^x^cur^(T[1-(depth[v]&1)].best(d[v]^x^cur)));
			cout<<ans<<" ";
		}
	}
	cout<<endl;
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