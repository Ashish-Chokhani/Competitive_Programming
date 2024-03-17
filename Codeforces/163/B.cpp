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
  for(auto &x:arr){
    cin>>x;
  }
  arr.push_back(99);
  ll flag=1,prev_val=0;
  auto canBreak=[&](ll i){
  	if(!flag) return false;
  	string s=to_string(arr[i]);
  	if(s.length()==1) return s[0]-'0'>=prev_val;
  	return s[0]-'0'>=prev_val && s[1]-'0'<=arr[i+1] && s[0]-'0'<=s[1]-'0';
  };
  string ans="YES";
  for(ll i=0;i<n;i++){
  	if(canBreak(i)){
  		prev_val=arr[i]%10;
  		continue;
  	}
  	else{
  		flag=0;
  		if(arr[i]<prev_val) ans="NO";
  		prev_val=arr[i];
  	}
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