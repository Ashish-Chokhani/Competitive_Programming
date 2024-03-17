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

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  map<ll,vector<ll>>mp;
  for(ll i=0;i<n;i++){
  	mp[arr[i]].push_back(i);
  }
  auto firstValidLeft=[&](ll val,ll i)->ll{
  	auto it=lower_bound(mp[val].begin(),mp[val].end(),i)-mp[val].begin();
  	return --it;
  };
  auto firstValidRight=[&](ll val,ll i)->ll{
  	auto it=lower_bound(mp[val].begin(),mp[val].end(),i)-mp[val].begin();
  	return it;
  };
  ll ans=0;
  vector<pair<ll,ll>>whenGood;
  for(ll i=0;i<n;i++){
  	ll cur=2*arr[i];
  	ll vall=-1,valr=n;
  	for(ll j=1;j<=10;j++){
  		vall=max(vall,firstValidLeft(j,i));
  		valr=min(valr,firstValidRight(cur-j,i));
  	}
  	if(vall!=-1 && valr!=n)
  	whenGood.push_back({vall,valr});
  }
  sort(whenGood.begin(),whenGood.end());
  auto isPresent=[&](ll x,ll y)->ll{
  	ll ind=lower_bound(whenGood.begin(),whenGood.end(),{x,0})-whenGood.begin();
  	
  };
  // For each l, find the minimum r such that it contains at least one good element in range(l,r)
  // Good when 2*A[j]=A[i]+A[k] when l=<i<j<k<=r
  // Effeciently need to find to whether there exists (x,y) such that l<=x<=y<=r 
  //cout<<ans<<endl;
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