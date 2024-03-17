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
  string s;
  cin>>s;
  ll n=s.length();
  map<char,vector<ll>>where;
  for(ll i=0;i<n;i++){
  	where[s[i]].push_back(i);
  }
  auto cntOccurences=[&](char ch,ll i){
  	ll ind=lower_bound(where[ch].begin(),where[ch].end(),i+1)-where[ch].begin();
  	ll sz=where[ch].size();
  	return sz-ind;
  };
  ll ans=0,extra=0;
  for(ll i=0;i<n-1;i++){
  	ll same=cntOccurences(s[i],i);
  	ll diff=n-1-i-same;
  	if(same>0) extra=1;
  	ans+=diff;
  }
  cout<<ans+extra<<endl;
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