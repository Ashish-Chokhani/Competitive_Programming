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

template<int MOD>
struct ModInt {
    long long v;
    ModInt(long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt& operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt& operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt& operator *= (const ModInt &other) {v = v * other.v % MOD; return *this;}
    ModInt& operator /= (const ModInt &other) {return *this *= inverse(other);}
    bool operator == (const ModInt &other) const {return v == other.v;}
    bool operator != (const ModInt &other) const {return v != other.v;}
    friend ModInt operator + (ModInt a, const ModInt &b) {return a += b;}
    friend ModInt operator - (ModInt a, const ModInt &b) {return a -= b;}
    friend ModInt operator * (ModInt a, const ModInt &b) {return a *= b;}
    friend ModInt operator / (ModInt a, const ModInt &b) {return a /= b;}
    friend ModInt operator - (const ModInt &a) {return 0 - a;}
    friend ModInt power(ModInt a, long long b) {ModInt ret(1); while (b > 0) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
    friend ModInt inverse(ModInt a) {return power(a, MOD - 2);}
    friend istream& operator >> (istream &is, ModInt &m) {is >> m.v; m.v = (-MOD < m.v && m.v < MOD) ? m.v : m.v % MOD; if (m.v < 0) m.v += MOD; return is;}
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
 
using Mint = ModInt<mod>;
const ll maxN=5e5+2;
vector<Mint>fact(maxN);

void computeFact(){
  fact[0]=1;
  for(ll i=1;i<maxN;i++){
    fact[i]=fact[i-1]*i;
  }
}

Mint NCR(ll n,ll r){
  Mint val=1;
  for(ll i=n;i>=(n-r+1);i--) val*=i;
  val=val/fact[r];
  return val;
}

void solve(){
	ll N,C;
	cin>>N>>C;
	ll adj[N+1][2];
	vector<ll>value(N);
	for(ll i=0;i<N;i++){
		ll u,v,val;
		cin>>u>>v>>val;
		if(u!=-1) u--;
		if(v!=-1) v--;
		adj[i][0]=u;
		adj[i][1]=v;
		value[i]=val;
	}
	//Handle -1 properly
	Mint ans=1;
	vector<ll>l_val(N),r_val(N);
	function<void(ll,ll,ll)>DFS=[&](ll cur,ll l,ll r){
		ll left_child=adj[cur][0];
		ll right_child=adj[cur][1];
		if(left_child!=-1) DFS(left_child,l,r);
		if(right_child!=-1) DFS(right_child,l,r+1);
		ll left_val=1,right_val=C;
		if(left_child!=-1) left_val=max(left_val,l_val[left_child]);
		if(right_child!=-1) right_val=min(right_val,r_val[right_child]);
		if(value[cur]!=-1) left_val=max(left_val,value[cur]);
		if(value[cur]!=-1) right_val=min(right_val,value[cur]);
		l_val[cur]=left_val;r_val[cur]=right_val;
    ll len=r-l+1;
    ans*=NCR((ll)r_val[cur]-l_val[cur]+len,len);
	};
	DFS(0,1,N);
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
    cin >> t;
    computeFact();
    while (t--)
    {
        solve();
    }
    return 0;
}