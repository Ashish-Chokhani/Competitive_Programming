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

void solve(){
	int a,b,n,m;
	cin>>a>>b>>n>>m;
	vector<pair<int,int>>chips(n);
	for(int i=0;i<n;i++) cin>>chips[i].first>>chips[i].second;
	vector<int>moves[4]; //L R D U
    map<pair<char,int>,int>mp;
    int cur_L=0,cur_R=0,cur_D=0,cur_U=0;
    for(int i=0;i<m;i++){
    	char ch;cin>>ch;
    	int k;cin>>k;
    	if(ch=='L'){
    		cur_L++;
    		moves[0].push_back(k);
    		mp[{'L',cur_L}]=i+1;
    	}
    	else if(ch=='R'){
    		cur_R++;
    		moves[1].push_back(k);
    		mp[{'R',cur_R}]=i+1;
    	}
    	else if(ch=='D'){
    		cur_D++;
    		moves[2].push_back(k);
    		mp[{'D',cur_D}]=i+1;
    	}
    	else if(ch=='U'){
    		cur_U++;
    		moves[3].push_back(k);
    		mp[{'U',cur_U}]=i+1;
    	}
    }
    mp[{'L',INF}]=mp[{'R',INF}]=mp[{'D',INF}]=mp[{'U',INF}]=INF;
    for(int i:{0,1,2,3}) for(int j=1;j<(int)moves[i].size();j++) moves[i][j]+=moves[i][j-1];
    auto when=[&](int i,int dis)->int{
    	auto ind=lower_bound(all(moves[i]),dis)-moves[i].begin();
    	if(ind==moves[i].size()) ind=INF;
    	else ind++;
    	return ind;
    };
    int score_Alice=0,score_Bob=0;
    for(auto it:chips){
    	int x=it.first,y=it.second;
    	int l_dist=y,r_dist=b-l_dist+1,u_dist=x,d_dist=a-u_dist+1;
    	int val=min({when(0,l_dist),when(1,r_dist),when(2,d_dist),when(3,u_dist)});
    	if(val==INF) continue;
    	int which_turn=INF;
    	which_turn=min(which_turn,mp[{'L',when(0,l_dist)}]);
    	which_turn=min(which_turn,mp[{'R',when(1,r_dist)}]);
    	which_turn=min(which_turn,mp[{'D',when(2,d_dist)}]);
    	which_turn=min(which_turn,mp[{'U',when(3,u_dist)}]);
    	if(which_turn&1) score_Alice++;
    	else score_Bob++;
    }
    cout<<score_Alice<<" "<<score_Bob<<endl;
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