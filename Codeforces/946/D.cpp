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
  int n;
  cin>>n;
  string s;
  cin>>s;
  int N=0,S=0,E=0,W=0;
  for(char &ch:s){
  	N+=ch=='N';S+=ch=='S';E+=ch=='E';W+=ch=='W';
  }
  if(N<S){
  	swap(N,S);
  	for(int i=0;i<n;i++){
	  	if(s[i]=='N') s[i]='S';
	  	else if(s[i]=='S') s[i]='N';
    }
  }
  if(E<W){
  	swap(E,W);
  	for(int i=0;i<n;i++){
	  	if(s[i]=='E') s[i]='W';
	  	else if(s[i]=='W') s[i]='E';
    }
  }
  if(((N-S)&1) || ((E-W)&1)){
  	cout<<"NO\n";
  	return;
  }
  // Handle the case when both are zero
  int dx=(E-W)/2,dy=(N-S)/2;
  int N1=0,S1=0,E1=0,W1=0;
  bool reached_dx=false,reached_dy=false;
  auto what=[&](int val,int type){
  	char ch='R';
  	if((type==0 && reached_dx) || (type==1 && reached_dy)) ch='H';
  	if(type==0) reached_dx|=(val==dx);
  	if(type==1) reached_dy|=(val==dy);
  	return ch;
  };
  string ans="";
  for(int i=0;i<n;i++){
  	N1+=s[i]=='N';S1+=s[i]=='S',E1+=s[i]=='E',W1+=s[i]=='W';
    if((s[i]=='N') || (s[i]=='S')) ans+=what(N1-S1,1);
  	else if(s[i]=='E' || s[i]=='W') ans+=what(E1-W1,0);
  }
  string temp=ans;
  sort(all(temp));
  if(temp[0]==temp.back()) ans="NO";
  if((dx==0 && dy==0 && (N>=2 || S>=2 || E>=2 && W>=2)) || (N==1 && S==1 && E==1 && W==1)){
  	ans="";
  	bool f1=false,f2=false;
  	if(N>=2 || S>=2){
  		for(int i=0;i<n;i++){
	  		if(!f1 && s[i]=='N') ans+='R';
	  		else if(!f2 && s[i]=='S') ans+='R';
	  		else ans+='H';
	  		f1|=s[i]=='N';f2|=s[i]=='S';
  	    }
  	}
  	else{
  		for(int i=0;i<n;i++){
	  		if(!f1 && s[i]=='E') ans+='R';
	  		else if(!f2 && s[i]=='W') ans+='R';
	  		else ans+='H';
	  		f1|=s[i]=='E';f2|=s[i]=='W';
  	    }	
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