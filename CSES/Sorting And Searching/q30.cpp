#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
             tree_order_statistics_node_update>ordered_set;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<pair<ll,ll>>intervals(n);
  for(pair<ll,ll>&interval:intervals){
    cin>>interval.first>>interval.second;
  }
  sort(intervals.begin(),intervals.end(),[](pair<ll,ll>&i1,pair<ll,ll>&i2){
  	return (i1.second<i2.second) || (i1.second==i2.second && i1.first>=i2.first);
  });
  ll ans=0,cur_sz=0;
  ordered_set end_points;
  cout<<"Now Printing\n";
  for(ll i=0;i<n;i++){
  	ll l=intervals[i].first;
  	ll r=intervals[i].second;
    ll picked_elements=cur_sz-end_points.order_of_key(l+1);
    if(picked_elements<k){
      cout<<l<<" "<<r<<"\n";
      end_points.insert(r);
      cur_sz++;
      ans++;
    }
  }
  cout<<ans<<"\n";
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