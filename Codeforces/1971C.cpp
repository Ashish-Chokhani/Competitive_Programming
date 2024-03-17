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
	ll n,k,d;
	cin>>n>>k>>d;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<ll>b(k);
	for(ll i=0;i<k;i++) cin>>b[i];
	ll ans=0;
	for(ll days=0;days<=min(d-1,2*n);days++){
		ll cur_cnt=0;
		for(ll i=0;i<n;i++){ //check if till val or n-1 and accordingly update current count
			cur_cnt+=arr[i]==i+1;
		}
		ll exploited=days+1;
		cur_cnt+=(d-exploited)/2;
		ans=max(ans,cur_cnt);
		for(ll i=0;i<b[days%k];i++) arr[i]++;
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