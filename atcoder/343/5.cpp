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
	ll V1,V2,V3;
	cin>>V1>>V2>>V3;
	struct P{
		ll x,y,z;
		P(ll _x,ll _y,ll _z): x(_x),y(_y),z(_z) {}
	};
	if(V1!=1029-2*V2-3*V3){
		cout<<"No\n";
		return;	
	}
	auto f=[&](P P1,P P2,P P3){
		return max(0LL,min({P1.x,P2.x,P3.x})+7-max({P1.x,P2.x,P3.x}))*
		max(0LL,min({P1.y,P2.y,P3.y})+7-max({P1.y,P2.y,P3.y}))*
		max(0LL,min({P1.z,P2.z,P3.z})+7-max({P1.z,P2.z,P3.z}));
	};
	
	
	ll a1=0,b1=0,c1=0,a2,b2,c2,a3,b3,c3;
	for(a2=-7;a2<=7;a2++) for(b2=-7;b2<=7;b2++) for(c2=-7;c2<=7;c2++){
		for(a3=-7;a3<=7;a3++) for(b3=-7;b3<=7;b3++) for(c3=-7;c3<=7;c3++){
			ll v3=f(P(a1,b1,c1),P(a2,b2,c2),P(a3,b3,c3));
			ll v2=f(P(a1,b1,c1),P(a2,b2,c2),P(a2,b2,c2))+f(P(a1,b1,c1),P(a3,b3,c3),P(a1,b1,c1))+f(P(a3,b3,c3),P(a2,b2,c2),P(a2,b2,c2))-3*v3;
			if(v2==V2 && v3==V3){
				cout<<"Yes\n";
				cout<<a1<<" "<<b1<<" "<<c1<<" ";
				cout<<a2<<" "<<b2<<" "<<c2<<" ";
				cout<<a3<<" "<<b3<<" "<<c3;
				return;
			}
		}
	}
	cout<<"No\n";
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