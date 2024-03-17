#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
const ll mod = 1000000007; //998244353
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

bool isEqual(string &t,ll i,ll j){
	return t[i]=='?' || t[j]=='?' || t[i]==t[j];
}

void solve(){
	string s;
	cin>>s;
	ll n=s.length();
	ll ans=0;
	bool found=false;
	for(ll len=n;len>=1;len--){
		if(len&1) continue;
		ll val=0;
		ll i=0,j=len/2;
		while(j<n){
			if(isEqual(s,i,j)){
				val++;
				if(val>=len/2){
					found=true;
					val=0;
				}
			}
			else val=0;
			i++;
			j++;
			if(found){
			ans=max(ans,len);
			break;
		    }
		}
	}
	printf("%d\n",ans);
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