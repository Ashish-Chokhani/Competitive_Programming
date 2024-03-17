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

ll binexp(ll a,ll n){
	ll res=1;
	while(n){
		if(n&1) res*=a;
		res%=mod;
		a*=a;
		a%=mod;
		n>>=1;
	}
	return res;
}

ll modInv(ll x){
	return binexp(x,mod-2);
}

ll G(ll a,ll b){
	if(a==0) return b;
	if(b==0) return a;
	if(a<b) swap(a,b);
	return G(b,a%b);
}

ll phi(ll n){
	ll ans=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ans=ans-ans/i;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n!=1) ans=ans-ans/n;
	return ans;
}

void solve(){
  ll n,m;
  cin>>n>>m;
  ll ans=0,val;
  for(ll i=1;i*i<=n;i++){
  	if(n%i==0){
  		val=(binexp(m,i)*phi(n/i))%mod;
  		ans+=val;
  		ans%=mod;
  		if(n/i!=i){
  			val=(binexp(m,n/i)*phi(i))%mod;
  			ans+=val;
  			ans%=mod;
  		}
  	}
  }
  ans*=modInv(n);
  ans%=mod;
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