#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
const ll mod = 1000000007; //998244353
// const ll INF = 1e18;
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
  ll n,q;
  cin>>n>>q;
  vector<string>grid(n);
  for(string &s:grid){
  	cin>>s;
  }
  vector<vector<ll>>dp(n,vector<ll>(n,0)),cnt(n,vector<ll>(n,0));
  for(ll i=0;i<n;i++){
  	for(ll j=0;j<n;j++){
	  	dp[i][j]=grid[i][j]=='*';
	  	if(i>=1) dp[i][j]+=dp[i-1][j];
	  	if(j>=1) dp[i][j]+=dp[i][j-1];
	  	if(i>=1 && j>=1) dp[i][j]-=dp[i-1][j-1];	
  	}
  }
  vector<pair<ll,ll>>queries;
  ll max_size=sqrt(q)+1;
  for(ll i=1;i<=q;i++){
  	ll type;
  	cin>>type;
  	if(type==1){
  		ll x,y;
  		cin>>x>>y;
  		--x;--y;
  		ll cur_size=(ll)queries.size();
  		if(cur_size<max_size) queries.push_back({x,y});
  		else{
  			// TODO: empty the list recompute the dp array
  			for(pair<ll,ll>p:queries){
  				ll x=p.first;
  				ll y=p.second;
  				if(grid[x][y]=='*') grid[x][y]='.';
  				else grid[x][y]='*';
  			}
  			queries.clear();
  			for(ll i=0;i<n;i++){
			  	for(ll j=0;j<n;j++){
			  	    dp[i][j]=0;	
			  	}
			}
  			for(ll i=0;i<n;i++){
			  	for(ll j=0;j<n;j++){
				  	dp[i][j]=grid[i][j]=='*';
				  	if(i>=1) dp[i][j]+=dp[i-1][j];
				  	if(j>=1) dp[i][j]+=dp[i][j-1];
				  	if(i>=1 && j>=1) dp[i][j]-=dp[i-1][j-1];	
			  	}
			}
			queries.push_back({x,y});
  		}
  	}
  	else{
  		ll x1,y1,x2,y2;
  		cin>>x1>>y1>>x2>>y2;
  		--x1;--y1;--x2;--y2;
  		ll ans=dp[x2][y2];
  		if(y1>=1) ans-=dp[x2][y1-1];
  		if(x1>=1) ans-=dp[x1-1][y2];
  		if(x1>=1 && y1>=1) ans+=dp[x1-1][y1-1];
  		vector<pair<ll,ll>>unique_pos;
  		for(pair<ll,ll>p:queries){
  			ll x=p.first;
  			ll y=p.second;
  			auto doesBelong=[&](){
  				return x1<=x && x<=x2 && y1<=y && y<=y2;
  			};
  			if(doesBelong()){
  				cnt[x][y]++;
  				if(cnt[x][y]==1) unique_pos.push_back({x,y});
  			}
  		}
  		for(auto it:unique_pos){
  		    ll x=it.first,
  		       y=it.second;
  		    ans+=cnt[x][y]&1 && grid[x][y]=='.';
  		    ans-=cnt[x][y]&1 && grid[x][y]=='*';
  		    cnt[x][y]=0;	
  		}
  		cout<<ans<<endl;
   	}
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