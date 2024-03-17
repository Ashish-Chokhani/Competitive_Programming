#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const double INF = 1e18;
const double epsilon = 0.0000000000000001;
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
	ll x,y,n;
	cin>>x>>y>>n;
	double cur_diff=INF;
	pair<ll,ll>ans;
	for(ll b=1;b<=n;b++){
		double val=(double)(x*b)/y-epsilon;
		ll a=round(val);
		double diff=abs((double)x/y-(double)a/b);
		if(diff<cur_diff){
			ans.first=a;
			ans.second=b;
			cur_diff=diff;
		}
	}
	cout<<ans.first<<"/"<<ans.second<<endl;
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