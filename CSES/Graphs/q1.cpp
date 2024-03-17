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

bool isValid(ll i,ll j,vector<vector<ll>>&vis,vector<string>&arr){
	ll n=vis.size();
	ll m=vis[0].size();
	return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && arr[i][j]!='#';
}

void DFS(ll i,ll j,vector<vector<ll>>&vis,vector<string>&arr){
	vis[i][j]=1;
	ll dx[]={-1,0,0,1};
	ll dy[]={0,-1,1,0};
	for(ll dir=0;dir<4;dir++){
		ll newX=i+dy[dir];
		ll newY=j+dx[dir];
		if(isValid(newX,newY,vis,arr)){
			DFS(newX,newY,vis,arr);
		}
	}
}

void solve(){
  ll n,m;
  cin>>n>>m;
  vector<string>arr(n);
  for(string &s:arr){
  	cin>>s;
  }
  ll nCompomnents=0;
  vector<vector<ll>>vis(n,vector<ll>(m,0));
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<m;j++){
  		if(!vis[i][j] && arr[i][j]=='.'){
  			nCompomnents++;
  			DFS(i,j,vis,arr);
  		}
  	}
  }
  cout<<nCompomnents<<"\n";
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