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
  ll n,l;
  cin>>n>>l;
  vector<ll>a(n+1),b(n+1);
  for(ll i=1;i<=n;i++){
  	cin>>a[i]>>b[i];
  }
  vector<pair<ll,ll>>adj[n+1];
  for(ll i=1;i<=n;i++){
  	for(ll j=1;j<=n;j++){
  		if(i==j) continue;
  		adj[i].push_back({a[j]+abs(b[j]-b[i]),j});
  	}
  }
  for(ll i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
  ll ans=0;
  for(ll i=1;i<=n;i++){
  	ll health=a[i],cnt=(a[i]<=l),cur_node=i;
  	vector<ll>vis(n+1,0);
  	vis[i]=1;
  	while(health<=l && cnt<=n){
  		ll minNode=-1,wt;
  		for(auto it:adj[cur_node]){
  			if(!vis[it.second]){
  				minNode=it.second;
  				vis[minNode]=1;
  				wt=it.first;
  				break;
  			}
  		}
  		if(minNode==-1) break;
  		if(health+wt>l) break;
  		health+=wt; 
  		cur_node=minNode;
  		cnt++;
  	}
  	ans=max(ans,cnt);
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
    while (t--)
    {
        solve();
    }
    return 0;
}