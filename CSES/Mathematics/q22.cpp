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
ll n,empty;

ll dx[4]={-1,0,1,0};
ll dy[4]={0,-1,0,1};

bool isSafePos(ll i,ll j){
	ll start_i=i/8;
	if(i<start_i) return false;
	if(i>start_i) return true;
	ll start_j=empty%8;
	return j>=start_j;
}

ll fun(ll i,ll j,ll k,ll empty){
	if(k==0) return 0;
	return 0;
	for(ll dir=0;dir<4;dir++){
		ll new_x=i+dy[dir];
		ll new_y=j+dx[dir];
	}
}

void solve(){
  cin>>n;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
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