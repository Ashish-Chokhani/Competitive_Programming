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

const ll maxN=2e5+2;
vector<ll>divisors[maxN];

void calculateDivisors(){
	for(ll i=1;i<maxN;i++){
	  	for(ll j=1;j*j<=i;j++){
	  		if(i%j==0){
	  			divisors[i].push_back(j);
	  			if(i/j!=j) divisors[i].push_back(i/j);
	  		}
	  	}
    }
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a==0) return b;
    else return gcd(b,a%b);
}

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  ll ans=0;
  for(int div:divisors[n]){
  	ll g=0;
  	for(ll i=0;i<div;i++){
  		ll mini=1e12;
  		for(ll j=i;j<n;j+=div){
  			mini=min(mini,arr[j]);
  		}
  		for(ll j=i;j<n;j+=div){
  			g=gcd(g,arr[j]-mini);
  		}
  	}
  	ans+=(g!=1);
  }
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
    calculateDivisors();
    while (t--)
    {
        solve();
    }
    return 0;
}