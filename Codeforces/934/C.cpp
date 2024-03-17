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
  vector<ll>arr(n);
  map<ll,ll>freq;
  for(ll &x:arr){
    cin>>x;
    freq[x]++;
  }
  ll flag=0;
  for(ll i=0;i<n;i++){
  	if(freq[i]==0){
  		cout<<i<<"\n";
  		return;
  	}
  	if(freq[i]>=2) continue;
  	else if(freq[i]==1){
  		if(flag==0) flag++;
  		else
  		{
  		cout<<i<<"\n";
  		return;
  	    }
  	}
  }
  cout<<n<<endl;
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    #ifdef CLEVERFOX
    cout<<"Hello\n";
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    //freopen("error.txt","w",stderr);
    #endif
    
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}