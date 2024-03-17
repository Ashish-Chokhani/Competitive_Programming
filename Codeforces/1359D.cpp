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

void nextGreater(vector<ll>&arr,vector<ll>&nge,ll n)
{
    stack<pair<ll,ll>>st;
    st.push({arr[n-1],n-1});
    for(ll i=n-2;i>=0;i--)
    {
        while(!st.empty() && (arr[i]>=st.top().first))
        {
            st.pop();
        }
        if(!st.empty())
        nge[i]=st.top().second;
        st.push({arr[i],i});
    }
}

void prevGreater(vector<ll>&arr,vector<ll>&pge,ll n)
{
    stack<pair<ll,ll>>st;
    st.push({arr[0],0});
    for(ll i=1;i<n;i++)
    {
        while(!st.empty() && (arr[i]>=st.top().first))
        {
            st.pop();
        }
        if(!st.empty())
        pge[i]=st.top().second;
        st.push({arr[i],i});
    }
}


void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    long long prefix[n];
    memset(prefix,0,sizeof(prefix));
    long long suffix[n];
    memset(prefix,0,sizeof(suffix));
    prefix[0]=arr[0];
    suffix[n-1]=arr[n-1];
    for(ll i=1;i<n;i++){
        prefix[i]=arr[i]+prefix[i-1];
    }
    for(ll i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+arr[i];
    }
    vector<ll>nge(n,n),pge(n,-1);
    nextGreater(arr,nge,n);
    prevGreater(arr,pge,n);
    segtree<max_t>Sg1,Sg2,Sg3;
    Sg1.init(n,prefix);
    Sg2.init(n,suffix);
    ll ans=0;
    ll val1,val2;
    for(ll i=0;i<n;i++)
    {
        val1=0;
        val2=0;
        if(max(0LL,pge[i]+1)<=i-1)
        val1=max(0LL,Sg2.query(max(0LL,pge[i]+1),i-1).val - suffix[i]);
        if(i+1<=min(n-1,nge[i]-1))
        val2=max(0LL,Sg1.query(i+1,min(n-1,nge[i]-1)).val - prefix[i]);
        ans=max(ans,val1+val2);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
