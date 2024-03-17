#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
//              tree_order_statistics_node_update>ordered_set;
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for set use less instead of less_equals
// for erase use: st.erase(st.find_by_order(st.order_of_key(val));

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s,num_t(0,0,0,0));
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = num_t(arr[l],arr[l],arr[l],arr[l]);

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
    	// may be something to perform
      return tree[i]=v;
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
	if (l > r) return num_t();
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) { 
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t();

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
};

struct max_t {
  long long val,maxPrefix,maxSuffix,totalSum;
  static const long long null_v = -9223372036854775807LL;

  max_t(): val(0),maxPrefix(0),maxSuffix(0),totalSum(0) {}
  max_t(long long v,long long pre,long long suf,long long s): val(max(0LL,v)),maxPrefix(max(0LL,pre)),maxSuffix(max(0LL,suf)),totalSum(s) {}

  max_t op(max_t& other) {
  	ll v1=maxSuffix+other.maxPrefix;
    return max_t(max({val, other.val,v1}),max(totalSum+other.maxPrefix,maxPrefix),max(other.maxSuffix,maxSuffix+other.totalSum),totalSum+other.totalSum);
  }
};

ll n,q;
const ll maxN=2e5+2;
ll arr[maxN];
segtree<max_t>Sg;

void solve(){
  cin>>n>>q;
  for(ll i=0;i<n;i++){
  	cin>>arr[i];
  }
  Sg.init(maxN,arr);
  while(q--){
  	ll k,x;
  	cin>>k>>x;
  	--k;
  	Sg.update(k,k,max_t(x,x,x,x));
  	cout<<Sg.query(0,n-1).val<<endl;
  }
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("error.txt","w",stderr);
    //#endif
    
    ll t;
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}