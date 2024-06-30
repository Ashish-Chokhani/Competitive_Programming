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
  int n;
  cin>>n;
  vector<int>arr(n);
  for(auto &x:arr) cin>>x;
  auto fill_gaps=[&](int l,int r)->int{
    assert(l<r);
  	if(l==-1 && r==n) for(int i=0;i<n;i++) arr[i]=1+(i&1);
  	else if(l==-1){
  		for(int i=r-1;i>=l+1;i--){
  			if((i&1)!=(r&1)) arr[i]=arr[i+1]<<1;
  			else arr[i]=arr[i+1]>>1;
  		}
  	}
  	else if(r==n){
  		for(int i=l+1;i<r;i++){
  			if((i&1)!=(l&1)) arr[i]=arr[i-1]<<1;
  			else arr[i]=arr[i-1]>>1;
  		}
  	}
  	else{
  		int i=l,j=r;
  		while(i<j-1){
  			if(arr[i]>arr[j]){
  				arr[i+1]= arr[i]==1?2:arr[i]>>1;
  				i++;
  			}
  			else{
  				arr[j-1]=arr[j]==1?2:arr[j]>>1;
  				j--;
  			}
  		}
  		return arr[j]==arr[i]>>1 || arr[i]==arr[j]>>1;
  	}
  	return 1;
  };
  int l=-1,r=-1;
  for(int i=0;i<n;i++){
  	if(arr[i]==-1) continue;
  	l=r;
  	r=i;
  	if(!fill_gaps(l,r)){
  		cout<<"-1 "<<endl;
  		return;
  	}
  }
  if(!fill_gaps(r,n)){
  	cout<<"-1 "<<r<<endl;
  	return;
  }
  for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];
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