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

const ll maxN=1e6+2;
ll lps[maxN];

void solve(){
	string s,t;
	cin>>s>>t;
	memset(lps,0,sizeof(lps));
	ll n=(ll)s.length(),m=(ll)t.length();
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
	ll i=0,j=0,ans=0;
	while(i<n){
		if(j==m){
			j=lps[j-1];
			ans++;
		}
		else{
			if(s[i]==t[j]){
				i++;
				j++;
			}
			else{
				if(j==0) i++;
				else{
					j=lps[j-1];
				}
			}
		}
	}
	if(j==m) ans++;
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