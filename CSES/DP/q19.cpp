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


// 1 signifies that position is already occupied
// 0 signied position is empty
bool isAvailable(ll prev_mask,ll i){
	return ((prev_mask>>i)&1) == 0;
}

bool CanPlaceVertically(ll prev_mask,ll i){
	if(i<1) return false;
	return isAvailable(prev_mask,i) && isAvailable(prev_mask,i-1);
}

bool CanPlaceHorizontally(ll prev_mask,ll i){
	return isAvailable(prev_mask,i);
}


void generateMasks(ll cur_mask,ll i,ll n,ll prev_mask,vector<ll>&new_masks){
	if(i<0){
		new_masks.push_back(cur_mask);
		return;
	}
	if(!isAvailable(prev_mask,i)){
		generateMasks(cur_mask,i-1,n,prev_mask,new_masks);
	}
	else{
		if(CanPlaceVertically(prev_mask,i)) generateMasks(cur_mask,i-2,n,prev_mask,new_masks);
		if(CanPlaceHorizontally(prev_mask,i)) generateMasks(cur_mask | (1LL<<i),i-1,n,prev_mask,new_masks);	
	}
}

ll countWays(ll col,ll cur_mask,ll n,vector<vector<ll>>&dp){
	if(col<0) return cur_mask==0;
	if(dp[col][cur_mask]!=-1) return dp[col][cur_mask];
	vector<ll>new_masks;
	generateMasks(0,n-1,n,cur_mask,new_masks);
	ll ans=0;
	for(auto mask:new_masks){
		ans+=countWays(col-1,mask,n,dp);
		ans%=mod;
	}
	return dp[col][cur_mask]=ans;
}

void solve(){
	
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>>dp(m+1,vector<ll>((1LL<<n)+1,-1));
  cout<<countWays(m-1,0,n,dp)<<"\n";
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