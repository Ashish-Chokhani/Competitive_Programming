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

ll binexp(ll a,ll n,ll p){
	ll result=1;
	a%=p;
	while(n){
		if(n&1) result*=a;
		result%=p;
		n>>=1;
		a=a*a;
		a%=p;
	}
	return result;
}

ll modInv(ll x,ll p){
	return binexp(x,p-2,p);
}

void solve(){
  ll n;
  cin>>n;
  ll ans=0;
  ll i=1;
  while(i<=n){
  	ll q=n/i;
  	ll i_prime=n/q+1;
  	auto findSum=[&](ll l,ll r){
  		l%=mod;
  		r%=mod;
  		ll sz=r-l+1;
  		ll sn=sz*(2*l+sz-1);
  		sn%=mod;
  		return sn;
  	};
  	ans+=findSum(i,i_prime-1)*q;
  	ans%=mod;
  	i=i_prime;
  }
  cout<<((ans*modInv(2,mod))%mod+mod)%mod<<endl;
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