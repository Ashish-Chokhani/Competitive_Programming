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

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);    
}
  

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll g=gcd(n,m);
	ll lc=(n*m)/g;
	ll l=1,r=1e18,ans;
	while(l<=r){
		ll mid=(l+r)>>1;
		ll c1=mid/n;
		ll c2=mid/m;
		ll c3=2*(mid/lc);
		ll c=c1+c2-c3;
		if(c==k){
			ans=mid;
		}
		if(c<k) l=mid+1;
		else r=mid-1;
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
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}