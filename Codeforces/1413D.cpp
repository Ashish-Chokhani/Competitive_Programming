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
  vector<ll>arr(2*n);
  stack<ll>st,f;
  string ans="YES";
  for(ll i=0;i<2*n;i++){
  	char ch;
  	cin>>ch;
  	if(ch=='+'){
  		arr[i]=-1;
  	}
  	else{
  		ll x;
  		cin>>x;
  		arr[i]=x;
  	}
  }
  for(ll i=2*n-1;i>=0;i--){
  	if(arr[i]>0){
  		if(!st.empty() && arr[i]>st.top()){
  			ans="NO";
  			break;
  		}
  		else{
  			st.push(arr[i]);
  		}
  	}
  	else{
  		if(st.empty()){
  			ans="NO";
  			break;
  		}
  		else{
  			ll val=st.top();
  			st.pop();
  			f.push(val);
  		}
  	}
  }
  if(ans=="NO"){
  	cout<<"NO\n";
  	return;
  }
  cout<<"YES\n";
  while(!f.empty()){
  	ll val=f.top();
  	f.pop();
  	cout<<val<<" \n"[f.size()==0];
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
    //cin >> t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}