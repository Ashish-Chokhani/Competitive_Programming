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
	ll res=1;
	while(n){
		if(n&1) res*=a;
		res%=p;
		n>>=1;
		a*=a;
		a%=p;
	}
	return res;
}
 
ll modInv(ll x){
	return binexp(x,mod-2,mod);
}
 
void solve(){
  ll N;
  cin>>N;
  ll A = N * N;
  ll B = (A+3*(N&1))/4;
  ll C = (A+(N&1))/2;
  printf("%lld\n", ((binexp(2, A,mod)+2*binexp(2, B,mod)+binexp(2, C,mod))*modInv(4)%mod));
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