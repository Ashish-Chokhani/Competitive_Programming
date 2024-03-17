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
	ll n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	ll firstA=n,lastB=-1;
	set<ll>badPos[2];
	for(ll i=0;i<n;i++){
		if(t[i]=='A' && firstA==n) firstA=i;
		if(t[i]=='B') lastB=i;
		if(s[i]==t[i]) continue;
	}
	for(ll i=0;i<n;i++){
		if(s[i]==t[i]) continue;
		if(s[i]=='B' && (lastB<i)){
			cout<<"-1\n";
			return;
		}
		if(s[i]=='A' && firstA>i){
			cout<<"-1\n";
			return;
		}
		badPos[s[i]-'A'].insert(i);
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		if(s[i]==t[i]) continue;
		if(badPos[s[i]-'A'].find(i)==badPos[s[i]-'A'].end()) continue;
		if(s[i]=='B'){
			auto it=badPos[0].lower_bound(i+1);
			ans++;
			if(it==badPos[0].end()){
				badPos[1].erase(i);
			}
			else{
				badPos[0].erase(it);
				badPos[1].erase(i);
			}
		}
		else ans++;
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