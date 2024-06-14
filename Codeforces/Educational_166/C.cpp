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
	int n,m;
	cin>>n>>m;
	vector<int>a(n+m+2),b(n+m+2);
	for(int i=1;i<=n+m+1;i++) cin>>a[i];
	for(int i=1;i<=n+m+1;i++) cin>>b[i];
	vector<vector<int>>suf(2,vector<int>(n+m+3)),t(2,vector<int>(n+m+2));
    vector<int>pre(n+m+2,0);
    for(int i=n+m+1;i>=1;i--){
    	suf[0][i]+=a[i]+suf[0][i+1];
    	suf[1][i]+=b[i]+suf[1][i+1];
    	t[0][i]=a[i]>b[i];t[1][i]=b[i]>a[i];
    }
    // Handle the last index
    for(int i=1;i<=n+m+1;i++){
    	pre[i]=pre[i-1]+max(a[i],b[i]);
    	t[0][i]+=t[0][i-1];
    	t[1][i]+=t[1][i-1];
    }
    auto findPos=[&](int x,int y)->pair<int,int>{
        int p1=lower_bound(all(t[0]),x)-t[0].begin();
        int p2=lower_bound(all(t[1]),y)-t[1].begin();
        return {p1,p2};
    };
    for(int i=1;i<=n+m+1;i++){
    	pair<int,int>pos=findPos(n,m);
    	if(min(pos.first,pos.second)>=i){
    	   int who=b[i]>a[i];
    	   if(who==0) pos=findPos(n+1,m);
    	   else pos=findPos(n,m+1);	
    	}
    	int x=pos.first,y=pos.second;
    	int ind=min(x,y);
    	int val=pre[ind]+suf[x<y][ind+1];
    	if(ind>=i) val-=max(a[i],b[i]);
    	else if(x<y) val-=b[i];
    	else val-=a[i];
    	cout<<val<<" \n"[i==n+m+1];
    }
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