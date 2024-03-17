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
  533000401,
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
  
  void init(int n, string s, ll k = 89, ll m = 1000000007) {
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
  ll n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  vector<ll>differ(n);
  differ[n-1]=differ[n-2]=n;
  for(ll i=n-3;i>=0;i--){
    if(s[i]==s[i+2]) differ[i]=differ[i+2];
    else differ[i]=i+2;
  }
  string_hash st;
  st.init(n,s,kk[4],primes[4]);
  auto isPalindrome=[&](int l,int r){
    return st.get_hash_prefix(l,r)==st.get_hash_suffix(l,r);
  };
  
  while(q--){
    ll l,r;
    cin>>l>>r;
    l--;r--;
    ll to;
    if((l&1)==(r&1)) to=r;
    else to=r-1;
    ll diff1=differ[l];
    bool val1=diff1>to;
    if(to==r) to--;
    else to++;
    ll diff2=differ[l+1];
    bool val2=diff2>to;
    ll k=r-l+1;
    ll ans=(k*(k+1))/2;
    ans--;
    k--;
    bool val3=s[l]==s[l+1] && (l+1)<r;
    ll temp=k;
    if(temp&1) temp--;
    ll hello=temp/2;
    if(val3 && val1 && val2) ans-=(hello*(hello+1));
    temp=k;
    if((temp&1)==0) temp--;
    ll z=(temp+1)/2;
    if(val1 && val2){
        ans-=z*z;
        ans++;
    }
    if(isPalindrome(l,r)) ans-=(r-l+1);
    cout<<ans<<endl;
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