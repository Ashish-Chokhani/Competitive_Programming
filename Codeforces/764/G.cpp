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

class DSU{
	vector<int>dsu_sz,dsu_par;
	int components;
	
public:
	DSU(int N){
		dsu_sz.resize(N,1); dsu_par.resize(N);
		for(int i=0;i<N;i++) dsu_par[i]=i;
		components=N;
	}
	
	int findPar(int u){
		if(dsu_par[u]==u) return u;
		return dsu_par[u]=findPar(dsu_par[u]);
	}	
	
	bool isSameComponent(int u,int v){
		return findPar(u)==findPar(v);
	}
	
    void merge(int u,int v){
    	if(isSameComponent(u,v)) return;
    	components--;
    	int par_u=findPar(u),par_v=findPar(v);
    	if(dsu_sz[par_u]>dsu_sz[par_v]) swap(par_u,par_v);
    	dsu_sz[par_v]+=dsu_sz[par_u];
    	dsu_par[par_u]=par_v;
    }
    
    int cntComponents(){
    	return components;
    }
};

void solve(){
	int N,M;
	cin>>N>>M;
	vector<array<int,3>>edges(M);
	for(int i=0;i<M;i++){
		cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
		--edges[i][1];--edges[i][2];
	}
	auto check=[&](vector<array<int,3>>A){
		DSU dsu(N);
		for(auto &[wt,u,v]:A) dsu.merge(u,v);
		return dsu.cntComponents()==1;
	};
	int ans=0;
	for(int i=31;i>=0;i--){
		vector<array<int,3>>temp;
		for(auto &[wt,u,v]:edges) if(!((wt>>i)&1)) temp.push_back({wt,u,v});
		if(check(temp)) edges=temp;
	    else ans|=1LL<<i;
	}
	cout<<ans<<endl;
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