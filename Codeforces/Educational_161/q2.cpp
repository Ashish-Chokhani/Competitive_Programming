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
  map<ll,ll>freq;
  vector<ll>distincts;
  for(auto &x:arr){
    cin>>x;
    freq[x]++;
    if(freq[x]==1) distincts.push_back(x);
  }
  ll ans=0;
  for(ll j=0;j<n;j++){
  	freq[arr[j]]--;
  	if(arr[j]==0) continue;
  	for(ll i=0;i<(ll)distincts.size();i++){
  		freq[distincts[i]]--;
  		if(distincts[i]==0 || freq[distincts[i]]<0) continue;
  		for(ll k=0;k<(ll)distincts.size();k++){
  			freq[distincts[k]]--;
  			if(distincts[k]==0 || freq[distincts[k]]<0) continue;
  			if(arr[j]>distincts[i]-distincts[k] && arr[j]>distincts[k]-distincts[i] && arr[j]<distincts[k]+distincts[i]){
  			ans+=(freq[distincts[distincts[i]]]+1)*(freq[distincts[k]]+1);
  			}
  			freq[distincts[k]]++;
  		}
  		freq[distincts[i]]++;
  	}
  	freq[arr[j]]++;
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}