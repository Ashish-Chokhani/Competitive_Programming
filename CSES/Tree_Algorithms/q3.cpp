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
vector<ll>adj[maxN];
ll ans=0;

ll DFS1(ll cur,ll par){
  ll d1=0,d2=0;
  for(auto child:adj[cur]){
    if(child==par) continue;
    ll str_line=DFS1(child,cur);
    if(str_line>=d1){
      d2=d1;
      d1=str_line;
    }
    else if(str_line>=d2){
      d2=str_line;
    }
  }
  ans=max(ans,d1+d2);
  return 1+d1;
}

void solve(){
  ll n;
  cin>>n;
  for(ll i=0;i<n-1;i++){
  	ll u,v;
  	cin>>u>>v;
  	--v;--u;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  DFS1(0,-1);
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