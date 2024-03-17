#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
	
	if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    if (tl == tr) return tree[i];
 
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
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;
 
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
 
struct sum_t {
  long long val;
  static const long long null_v = 0;
 
  sum_t(): val(0) {}
  sum_t(long long v): val(v) {}
 
  sum_t op(sum_t& other) {
    return sum_t(val + other.val);
  }
  
  sum_t lazy_op(sum_t& v, ll size) {
    return sum_t(val + v.val * size);
  }
};


vector<vector<ll>> dp(100002, vector<ll>(13,0));

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll>arr(n);
    ll freq[n];
    memset(freq,0,sizeof(freq));
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]--;
    }
    //freq[arr[0]]++;
    segtree<sum_t> Sg[12];
    for(ll i=0;i<12;i++)
    {
        Sg[i].init(n,freq);
    }
    for(ll index=0;index<n;index++)
    {
        dp[index][1]=1;
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=2;j<=k+1;j++)
        {
            dp[i][j]=Sg[j-1].query(0,arr[i]).val;
        }
        for(ll j=1;j<=k;j++)
        {
           Sg[j].update(arr[i],arr[i],dp[i][j]);
        }
        ans+=dp[i][k+1];
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}