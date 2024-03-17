#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
double pi=3.141592653589793;
 
template <typename num_t> 
struct segtree {
  ll n, depth;
  vector<num_t> tree, lazy;
 
  void init(ll s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }
 
  num_t init(ll i, ll l, ll r, long long* arr) {
    if (l == r) return tree[i] = arr[l];
 
    ll mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }
 
  void update(ll l, ll r, num_t v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }
 
  num_t update(ll i, ll tl, ll tr, ll ql, ll qr, num_t v) {
    eval_lazy(i, tl, tr);
	
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    ll mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }
 
  num_t query(ll l, ll r) {
	if (l > r) return num_t::null_v;
    return query(0, 0, n-1, l, r);
  }
 
  num_t query(ll i, ll tl, ll tr, ll ql, ll qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t::null_v;
 
    ll mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
 
  void eval_lazy(ll i, ll l, ll r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }
 
    lazy[i] = num_t();
  }
};
 
struct max_t {
  long long val;
  static const long long null_v = -9223372036854775807LL;
 
  max_t(): val(0) {}
  max_t(long long v): val(v) {}
 
  max_t op(max_t& other) {
    return max_t(max(val, other.val));
  }
  
  max_t lazy_op(max_t& v, ll size) {
    return max_t(val + v.val);
  }
};
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n),c(n);
    vector<pair<ll,ll>>arr(n);
    map<ll,ll>mp;
    for(ll i=0;i<n;i++)
    {
        ll r,h;
        cin>>r>>h;
        a[i]=r*r*h;
        arr[i]={a[i],i};
    }
    sort(arr.begin(),arr.end());
    for(ll i=0;i<n;i++)
    {
        b[arr[i].second]=i;
    }
    for(ll i=0;i<n;i++)
    {
        c[arr[i].second]=i;
        if(i>=1 && arr[i].first==arr[i-1].first)
        c[arr[i].second]=c[arr[i-1].second];
    }
    segtree<max_t>sg;
    ll dp[n];
    memset(dp,0,sizeof(dp));
    sg.init(n,dp);
    dp[0]=a[0];
    sg.update(b[0],b[0],dp[0]);
    for(ll i=1;i<n;i++)
    {
        dp[i]=max(a[i],a[i]+sg.query(0,c[i]-1).val);
        sg.update(c[i],c[i],dp[i]);
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    double z=(double)ans*pi;
    cout<<setprecision(28)<<z<<"\n";
}
 
int main()
{
    solve();
    return 0;
}