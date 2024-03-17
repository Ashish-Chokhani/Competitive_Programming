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

const ll maxN=11;
vector<ll>lps(maxN,0);

void solve(){
	string t;
	cin>>t;
	ll m=(ll)t.length();
	auto getLPS=[&](){
		ll j=0,i=1;
		while(i<m){
			if(t[i]==t[j]){
			lps[i]=j+1;
			i++;j++;
		    }
		    else{
		    	if(j==0) i++;
		    	else{
		    		j=lps[j-1];
		    	}
		    }
		}
	};
	getLPS();
	vector<ll>ans;
	ll j=lps[m-1];
	while(j>0){
		ans.push_back(j);
		j=lps[j-1];
	}
	sort(ans.begin(),ans.end());
	for(ll &x:ans) cout<<x<<" ";
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
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}