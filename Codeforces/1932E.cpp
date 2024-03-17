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
vector<ll>color(maxN);
vector<ll>adj[maxN];
ll n,ans;
map<ll,ll>mp[maxN];

void merge(ll cur,ll child){
	if(mp[child].size()>mp[cur].size()) swap(mp[child],mp[cur]);
	for(auto it:mp[child]){
		ans+=1LL*mp[cur][it.first]*it.second;
		mp[cur][it.first]+=it.second;
	}
	mp[cur][color[cur]]=1;
	mp[child].clear();
}

void DFS(ll cur,ll par){
	mp[cur][color[cur]]=1;
  	for(ll child:adj[cur]){
  		if(child==par) continue;
  		DFS(child,cur);
  		merge(cur,child);
  	}
}

void solve(){
  cin>>n;
  for(ll i=0;i<n;i++){
  	adj[i].clear();
  	mp[i].clear();
  }
  ans=0;
  for(ll i=0;i<n;i++){
    cin>>color[i];
  }
  for(ll i=0;i<n-1;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  DFS(0,-1);
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