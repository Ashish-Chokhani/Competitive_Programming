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

vector<ll> assign_weights(ll l,ll r){
	ll len=r-l+1;
	ll mid=(len+1)/2;
	--mid;
	vector<ll>arr(len);
	arr[mid]=len;
	ll i=mid-1;
	ll val=1;
	while(i>=0) arr[i--]=val++;
	ll j=mid+1;
	val=len-1;
	while(j<len) arr[j++]=val--;
	ll diff=r-len;
	for(ll i=0;i<len;i++) arr[i]+=diff;
	return arr;
}

void solve(){
	ll n,k;
	cin>>n>>k;
	ll cliques=(n+k-1)/k;
	ll id=1;
	vector<ll>which_clique(n),weights(n);
	ll clicque_size=k;
	for(ll i=1;i<=n;i+=clicque_size){
		vector<ll>arr=assign_weights(i,min(n,i+clicque_size-1));
		for(ll j=0;j<arr.size();j++){
			which_clique[i+j-1]=id;
			weights[i+j-1]=arr[j];
		}
		id++;
	}
	for(auto it:weights) cout<<it<<" ";
	cout<<endl;
	cout<<cliques<<endl;
	for(auto it:which_clique) cout<<it<<" ";
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