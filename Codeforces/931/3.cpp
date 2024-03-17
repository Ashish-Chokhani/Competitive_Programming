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

ll query(ll x,ll y){
	cout<<"? "<<x<<" "<<y<<endl;
	cout.flush();
	ll z;
	cin>>z;
	return z;
}

void solve(){
	ll n,m;
	cin>>n>>m;
	ll d=query(1,1);
	ll d1=query(1,m);
	ll d2=query(n,1);
	ll x1=(d1+d+3-m)/2;
	x1=max(1LL,min(n,x1));
	ll y1=(d+1+m-d1)/2;
	y1=max(1LL,min(m,y1));
	ll x2=(d+n+1-d2)/2;
	x2=max(1LL,min(n,x2));
	ll y2=(d+d2+3-n)/2;
	y2=max(1LL,min(m,y2));
	if(query(x1,y1)==0) cout<<"! "<<x1<<" "<<y1<<endl;
	else cout<<"! "<<x2<<" "<<y2<<endl;
	cout.flush();
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