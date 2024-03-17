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

ll n;
const ll maxN=2e5+2;
vector<ll>adj[maxN];
ll weights[maxN][2];
ll good[maxN][2];
vector<ll>ans(maxN,0);
ll isGood[maxN];

void DFS(ll cur,ll par){
	good[cur][1]=1;
	
	weights[cur][0]=1;
	weights[cur][1]+=cur!=0;
	for(ll child:adj[cur]){
		if(child==par) continue;
		DFS(child,cur);
		good[cur][0]+=max(good[child][1],good[child][0]);
		good[cur][1]+=good[child][0];
		weights[cur][1]+=weights[child][0];
	}
}

void assign_weights(ll cur,ll par,bool bad){
	bool f=true;
	
	if(bad || good[cur][0]>good[cur][1]){
		isGood[cur]=false;
		f=false;
	}
	else isGood[cur]=true;
	for(auto it:adj[cur]){
		if(it!=par){
			assign_weights(it,cur,f);
		}
	}
}

void solve(){
  cin>>n;
  memset(weights,0,sizeof(weights));
  memset(good,0,sizeof(good));
  memset(isGood,0,sizeof(isGood));
  for(ll i=0;i<n-1;i++){
  	ll u,v;
  	cin>>u>>v;
  	--u;--v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  if(n==2){
  	cout<<"2 2\n1 1\n";
  	return;
  }
  DFS(0,-1);
  assign_weights(0,-1,false);
  for(ll i=0;i<n;i++){
  	if(isGood[i]) ans[i]=weights[i][1];
  	else ans[i]=weights[i][0];
  }
  ll s=accumulate(ans.begin(),ans.end(),0);
  cout<<max(good[0][0],good[0][1])<<" "<<s<<endl;
  for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
  cout<<endl;
  // cout<<good[1][0]<<" "<<good[1][1]<<endl;
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