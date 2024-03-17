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

void solve(){
	string s1,s2;
	cin>>s1>>s2;
	ll n=s1.length(),m=s2.length();
	vector<ll>prev(m+1,INF);
	for(ll j=0;j<=m;j++){
		prev[j]=j;
	}
	for(ll i=1;i<=n;i++){
		vector<ll>cur(m+1,INF);
		cur[0]=i;
		for(ll j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]) cur[j]=min(cur[j],prev[j-1]);
			else{
				cur[j]=min(cur[j],1+prev[j-1]);
				cur[j]=min(cur[j],1+cur[j-1]);
				cur[j]=min(cur[j],1+prev[j]);
			}
		}
		prev=cur;
	}
	cout<<prev[m]<<"\n";
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