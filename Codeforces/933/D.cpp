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
	ll n,m,x;
	cin>>n>>m>>x;
	--x;
	auto findClockwise=[&](ll i,ll dis){
		return (i+dis)%n;
	};
	auto findAntiClockwise=[&](ll i,ll dis){
		return (i-dis+n)%n;
	};
	set<ll>st;
	st.insert(x);
	for(ll i=0;i<m;i++){
		ll dis;
		cin>>dis;
		char ch;
		cin>>ch;
		if(ch=='?'){
			set<ll>temp;
			for(auto it:st) temp.insert(findClockwise(it,dis));
			for(auto it:st) temp.insert(findAntiClockwise(it,dis));
			st=temp;
		}
		else if(ch=='0'){
			set<ll>temp;
			for(auto it:st) temp.insert(findClockwise(it,dis));
			st=temp;
		}
	    else{
			set<ll>temp;
			for(auto it:st) temp.insert(findAntiClockwise(it,dis));
			st=temp;
		}
	}
	cout<<st.size()<<endl;
	for(auto it:st) cout<<it+1<<" ";
	cout<<endl;
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