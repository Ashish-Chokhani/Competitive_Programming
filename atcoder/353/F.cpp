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
	int K,Sx,Sy,Tx,Ty;
	cin>>K;
	cin>>Sx>>Sy;
	cin>>Tx>>Ty;
	auto isBadTile=[&](int x,int y)->bool{
		return x%2==y%2;
	};
	auto getDistBwGoodTiles=[&](int x1,int y1,int x2,int y2)->int{
		int q1=floor_div(x1,K)*x1;
		int q2=floor_div(x2,K)*x2;
		int q3=floor_div(y1,K)*y1;
		int q4=floor_div(y2,K)*y2;
		int q5=ceil_div(x1,K)*x1;
		int q6=ceil_div(x2,K)*x2;
		int q7=ceil_div(y1,K)*y1;
		int q8=ceil_div(y2,K)*y2;
		
		if(q1==q2 && q3==q4) return 0;
		if(q1==q2) return abs(q4-q3)/K;
		if(q3==q4) return q2-q1;
		return q2-q5+q4-q7;
	};
	
	auto getNextGoodTile=[&](int i,int x,int y)->array<int,3>{
		int src_x=x,src_y=y;
		int dis=0;
		if(isBadTile(src_x,src_y)) return {dis,src_x,src_y};
		if(i==0){
			dis=ceil_div(src_y,K)*src_y+1-src_y;
			src_y=ceil_div(src_y,K)*src_y+1;
		}
		else if(i==1){
			dis=src_x-floor_div(src_x,K)*src_x+1;
			src_x=floor_div(src_x,K)*src_x-1;
		}
		else if(i==2){
			dis=ceil_div(src_x,K)*src_x+1-src_x;
			src_x=ceil_div(src_x,K)*src_x+1;
		}
		else{
			dis=src_y-floor_div(src_y,K)*src_y+1;
			src_y=floor_div(src_y,K)*src_y-1;
		}
		return {dis,src_x,src_y};
	};
	//Upward: dis=ceil_div(y1,K)*y1+1-y1;
	//Left:   dis=x1-floor_div(x1,K)*x1+1
	//Right:  dis=ceil_div(x1,K)*x1+1-x1;
	//Down:   dis=y1-floor_div(y1,K)*y1+1;
	cout<<Sx<<" "<<Sy<<" "<<Tx<<" "<<Ty<<endl;
	int ans=INF;
	for(int i=0;i<4;i++){
		auto nextTile_src=getNextGoodTile(i,Sx,Sy);
		
		//Accout for K=1 and K=2 cases
		//Correct the formula
		for(int j=0;j<4;j++){
			auto nextTile_dest=getNextGoodTile(j,Tx,Ty);
			int dis1=nextTile_src[0],dis2=nextTile_dest[0];
			int x1=nextTile_src[1],y1=nextTile_src[2],x2=nextTile_dest[1],y2=nextTile_dest[2];
			cout<<i<<" "<<j<<" "<<dis1<<" "<<dis2<<" "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
			ans=min(ans,dis1+dis2+getDistBwGoodTiles(x1,y1,x2,y2));
		}
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