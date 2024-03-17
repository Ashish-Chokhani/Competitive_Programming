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

ll binexp(ll x,ll n,ll p){
	ll res=1;
	while(n){
		if(n&1) res*=x;
		res%=p;
		n>>=1;
		x*=x;
		x%=p;
	}
	return res;
}

ll modInv(ll x,ll p){
	return binexp(x,p-2,p);
}

void solve(){
  ll n;
  cin>>n;
  ll cnt_divisors=1,sum_divisors=1,prod_divisors=1;
  vector<ll>base,exponent;
  ll oddPos=-1;
  while(n--){
  	ll x,k;
  	cin>>x>>k;
  	cnt_divisors*=(k+1);
  	cnt_divisors%=mod;
  	ll val=((binexp(x,k+1,mod)-1)%mod+mod)%mod;
  	val*=modInv(x-1,mod);
  	val=((val%mod)+mod)%mod;
  	sum_divisors*=val;
  	sum_divisors%=mod;
  	base.push_back(x);
  	exponent.push_back(k);
  	if(k&1){
  		oddPos=exponent.size()-1;
  	}
  }
  if(oddPos!=-1){
  	ll gamma=1;
  	for(ll i=0;i<(ll)exponent.size();i++){
  		if(i==oddPos) gamma=gamma*((exponent[i]+1)/2);
  		else gamma=gamma*(exponent[i]+1);
  		gamma%=(mod-1);
  	}
  	for(ll i=0;i<(ll)exponent.size();i++){
  		prod_divisors*=binexp(base[i],(exponent[i]*gamma)%(mod-1),mod);
  		prod_divisors%=mod;
  	}
  }
  else{
  	ll gamma=1;
  	for(ll i=0;i<(ll)exponent.size();i++){
  		gamma=gamma*(exponent[i]+1);
  		gamma%=(mod-1);
  	}
  	for(ll i=0;i<(ll)exponent.size();i++){
  		prod_divisors*=binexp(base[i],(exponent[i]/2*gamma)%(mod-1),mod);
  		prod_divisors%=mod;
  	}
  }
  cout<<cnt_divisors<<" "<<sum_divisors<<" "<<prod_divisors<<endl;
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