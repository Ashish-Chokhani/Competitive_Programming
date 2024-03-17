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
// for erase use: st.erase(st.find_by_order(val);

void solve(){
	ll n,m,q;
	cin>>n>>m>>q;
	vector<pair<ll,ll>>adj[n+1];
	vector<vector<ll>>cost(n,vector<ll>(n,INF));
	for(ll i=0;i<m;i++){
		ll u,v,wt;
		cin>>u>>v>>wt;
		--u;--v;
		cost[u][v]=min(cost[u][v],wt);
		cost[v][u]=min(cost[v][u],wt);
	}
	for(ll via=0;via<n;via++){
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				if(i==j){
					cost[i][j]=0;
					continue;
				}
				cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
			}
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		--u;--v;
		ll val=-1;
		if(cost[u][v]!=INF) val=cost[u][v];
		cout<<val<<"\n";
	}
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