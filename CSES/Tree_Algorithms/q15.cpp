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

const ll maxN=1e3+2,p=998244353;
vector<vector<ll>>grid(maxN,vector<ll>(maxN,0)),vis(maxN,vector<ll>(maxN,0)),isBridge(maxN,vector<ll>(maxN,0));
ll dx[4]={-1,0,1,0};
ll dy[4]={0,1,0,-1};
vector<vector<ll>>tin(maxN,vector<ll>(maxN,0));
vector<vector<ll>>low(maxN,vector<ll>(maxN,INF));
ll timer=1,n,m,nComponents=0,cntHashes=0;

ll binexp(ll a, ll b, ll m)
{
    if (b == 0)
        return 1ll;
    if (b == 1)
        return a % m;
    if (b % 2)
        return (a * binexp(a, b - 1, m)) % m;
    return binexp((a * a) % m, b / 2, m);
}


// To calculate modular inverse
ll mod_inv(ll x)
{
    return binexp(x, p - 2, p);
}

bool isValid(ll i,ll j){
	return i>=0 && i<n && j>=0 && j<m && grid[i][j]==1;
}

void DFS(pair<ll,ll>cur,pair<ll,ll>par){
	ll i=cur.first;
	ll j=cur.second;
	vis[i][j]=1;
	tin[i][j]=low[i][j]=timer++;
	for(ll dir=0;dir<4;dir++){
		ll new_i=i+dx[dir];
		ll new_j=j+dy[dir];
		pair<ll,ll>new_loc={new_i,new_j};
		if(!isValid(new_i,new_j) || new_loc==par) continue;
		
		if(!vis[new_i][new_j]) DFS({new_i,new_j},{i,j});
		
		low[i][j]=min(low[i][j],low[new_i][new_j]);
		if(low[new_i][new_j]>tin[i][j]){
			isBridge[i][j]++;
			isBridge[new_i][new_j]++;
		}
	}
}

bool isAlone(ll i,ll j){
	ll cnt=0;
	if(i>=1 && grid[i-1][j]) cnt++;
	if(j>=1 && grid[i][j-1]) cnt++;
	if(i<n-1 && grid[i+1][j]) cnt++;
	if(j<m-1 && grid[i][j+1]) cnt++;
	return cnt==0;
}

ll cntDegree(ll i,ll j){
	ll cnt=0;
	if(i>=1 && grid[i-1][j]) cnt++;
	if(j>=1 && grid[i][j-1]) cnt++;
	if(i<n-1 && grid[i+1][j]) cnt++;
	if(j<m-1 && grid[i][j+1]) cnt++;
	return cnt;
}

void solve(){
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			char ch;
			cin>>ch;
			grid[i][j]=(ch=='#');
			cntHashes+=(ch=='#');
		}
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(!vis[i][j] && isValid(i,j)){
				DFS({i,j},{-1,-1});
				nComponents++;
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(!grid[i][j]) continue;
			if(isAlone(i,j)) ans+=nComponents-1;
			else{
				if(isBridge[i][j] && cntDegree(i,j)>1) ans+=nComponents+1;
				else ans+=nComponents;
			}
		}
	}
	ans=(ans*mod_inv(cntHashes))%p;
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