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

const int MAXN = 1e6+7;
const ll p=1000000007;
long long fac[MAXN + 1], inv[MAXN + 1];
 
/** Computes x^y modulo p in O(log p) time. */
ll exp(ll x, ll y, ll p)
{
    ll res = 1;
    x %= p;
    while (y)
    {
        if (y & 1)
        {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y >>= 1;
    }
    return res;
}
 
/** Precomputes n! from 0 to MAXN. */
void factorial(ll p)
{
    fac[0] = 1;
    for (ll i = 1; i <= MAXN; i++)
    {
        fac[i] = fac[i - 1] * i % p;
    }
}
 
/** Precomputes all modular inverse factorials from 0 to MAXN in O(n + log p) time */
void inverses(ll p)
{
    inv[MAXN] = exp(fac[MAXN], p - 2, p);
    for (ll i = MAXN; i >= 1; i--)
    {
        inv[i - 1] = inv[i] * i % p;
    }
}

void solve(){
  ll n;
  cin>>n;
  string s;
  cin>>s;
  ll cnt_open=0,cnt_close=0;
  if(n&1){
  	cout<<"0\n";
  	return;
  }
  for(char ch:s){
    cnt_open+=ch=='(';
    cnt_close+=ch==')';
    if(cnt_open<cnt_close){
      cout<<"0\n";
      return;
    }
  }
  if(cnt_open>(n>>1) || cnt_close>(n>>1)){
    cout<<"0\n";
    return;
  }
  factorial(p);
  inverses(p);
  auto compute_nCr=[&](ll n,ll r){
    n%=mod;
    r%=mod;
    ll ans=fac[n];
    ans*=inv[r];
    ans%=mod;
    ans*=inv[n-r];
    ans%=mod;
    return ans;
  };
  ll cur_x=cnt_open+cnt_close;
  ll cur_y=cnt_open-cnt_close;
  ll reflected_x=cur_x;
  ll reflected_y=-(2+cur_y);
  auto compute_val=[&](ll cur_x,ll cur_y){
    ll dst_x=n;
    ll dst_y=0;
    return compute_nCr(dst_x-cur_x,(dst_x+dst_y-cur_x-cur_y)/2);
  };
  ll ans=compute_val(cur_x,cur_y);
  ans-=compute_val(reflected_x,reflected_y);
  ans%=mod;
  ans=(ans+mod)%mod;
  cout<<ans<<endl;
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