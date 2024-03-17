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
	ll n,L;
	cin>>n>>L;
	vector<pair<ll,ll>>arr(n);
	for(ll i=0;i<n;i++) cin>>arr[i].second>>arr[i].first;
	sort(arr.begin(),arr.end());
    ll ans=0;
    for(ll i=0;i<n;i++){
    	ll sigma_ai=0;
    	multiset<ll>st;
    	for(ll j=i;j<n;j++){
    		sigma_ai+=arr[j].second;
    		st.insert(arr[j].second);
    		ll cur=arr[j].first-arr[i].first;
    		ll cnt=0;
    		while(!st.empty() && cur+sigma_ai>L){
    			ll maxi=*st.rbegin();
    			st.erase(st.find(maxi));
    			sigma_ai-=maxi;
    		}
    		ans=max(ans,(ll)st.size());
    	}
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