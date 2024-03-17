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
	ll h,w,xa,ya,xb,yb;
	cin>>h>>w>>xa>>ya>>xb>>yb;
	if(xa>=xb){
		cout<<"Draw\n";
		return;
	}
	ll diff=xb-xa;
	ll nMoves_Alice=(diff+1)/2;
	ll nMoves_Bob=diff>>1;
	ll maxLeft_Alice=max(1LL,ya-nMoves_Alice);
	ll maxRight_Alice=min(w,ya+nMoves_Alice);
	ll maxLeft_Bob=max(1LL,yb-nMoves_Bob);
	ll maxRight_Bob=min(w,yb+nMoves_Bob);
	
	auto doesIntersect=[&](ll l1,ll r1,ll l2,ll r2){
		return l1<=l2 && r1>=r2;
	};
	string ans="Draw";
	if(diff & 1){
		//Check if Alice can win 
		if(doesIntersect(maxLeft_Alice,maxRight_Alice,maxLeft_Bob,maxRight_Bob)) ans="Alice";
	}
	else{
		//Check if Bob can win
		if(doesIntersect(maxLeft_Bob,maxRight_Bob,maxLeft_Alice,maxRight_Alice)) ans="Bob";
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