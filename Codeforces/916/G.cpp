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

vector<vector<int>>solution(vector<vector<int>>&grid,vector<vector<int>>taxi_stands,vector<int>&passenger){
	int a=passenger[0],b=passenger[1],n=grid.size(),m=grid[0].size(),k=taxi_stands.size();
	vector<vector<int>>dist(n,vector<int>(m,INF));
	pair<int,int>par[n][m];
	queue<array<int,2>>q;
    q.push({a,b});
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    auto isValid=[&](int i,int j){
    	return i>=0 && j>=0 && i<n && j<m && dist[i][j]==INF && grid[i][j]==0;
    };
    dist[a][b]=0;
    while(!q.empty()){
    	int x=q.front()[0],y=q.front()[1];
    	q.pop();
    	for(int dir=0;dir<4;dir++){
    		int r=x+dx[dir],c=y+dy[dir];
    		if(!isValid(r,c)) continue;
    		dist[r][c]=1+dist[x][y];
    		par[r][c]={x,y};
    		q.push({r,c});
    	}
    }
    int ans=INF,x=-1,y=-1;
    vector<vector<int>>output;
    for(int i=0;i<k;i++) for(int j=0;j<2;j++){
    	if(taxi_stands[i][j]<ans){
    		ans=taxi_stands[i][j];
    		x=i;y=j;
    	}
    }
    int cur_x=x,cur_y=y;
    if(ans!=INF){
    	output.push_back({cur_x,cur_y});
    	while(cur_x!=a || cur_y!=b){
    		int p1=par[cur_x][cur_y].first,p2=par[cur_x][cur_y].second;
    		output.push_back({p1,p2});
    		cur_x=p1,cur_y=p2;
    	}
    }
    return output;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>grid(n,vector<int>(m));
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>grid[i][j];
	int k;
    cin>>k;
	vector<vector<int>>taxi_stands(k,vector<int>(2));
	for(int i=0;i<k;i++) cin>>taxi_stands[i][0]>>taxi_stands[i][1];
	vector<int>passenger(2);
    cin>>passenger[0]>>passenger[1];
    vector<vector<int>>ans=solution(grid,taxi_stands,passenger);
    debug(ans); 
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