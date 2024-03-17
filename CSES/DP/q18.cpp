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

ll dp[20][10][2][2];

ll fun(ll cntDigits,ll last_digit,ll leadingZeros,ll tight,string &s){
	if(cntDigits==0) return 1;
	if(last_digit!=-1 && dp[cntDigits][last_digit][leadingZeros][tight]!=-1) return dp[cntDigits][last_digit][leadingZeros][tight];
	ll lb=0;
	ll ub=tight?s[s.length()-cntDigits]-'0':9;
	ll val=0;
	for(ll digit=lb;digit<=ub;digit++){
		if(digit==last_digit && !leadingZeros){
			continue;
		}
		val+=fun(cntDigits-1,digit,digit==0 && leadingZeros,tight & (digit==ub),s);
	}
	if(last_digit!=-1) dp[cntDigits][last_digit][leadingZeros][tight]=val;
	return val;
}

void solve(){
	ll a,b;
	cin>>a>>b;
	string s1=to_string(b);
	string s2=to_string(a-1);
	memset(dp,-1,sizeof(dp));
	ll ans1=fun(s1.length(),-1,1,1,s1);
	memset(dp,-1,sizeof(dp));
	ll ans2=fun(s2.length(),-1,1,1,s2);
	cout<<ans1-ans2<<"\n";
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