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
  set<ll>present;
  for(ll i=0;i<=n;i++) present.insert(i);
  for(auto &x:arr){
    cin>>x;
    if(present.find(x)!=present.end()) present.erase(x);
  }
  ll MEX=*present.begin();
  if(MEX==0){
  	cout<<"2\n";
	 cout<<"1 "<<n-1<<"\n";
	 cout<<n<<" "<<n<<endl;
	 return;
  }
  map<ll,ll>mp;
  ll cnt=0,i;
  for(i=0;i<n;i++){
  	if(mp[arr[i]]==0 && arr[i]<MEX) cnt++;
  	mp[arr[i]]=1;
  	if(cnt==MEX) break;
  }
  if(i>=n-1){
  	cout<<"-1\n";
  	return;
  }
  mp.clear();
  for(ll j=i+1;j<n;j++) if(arr[j]<MEX) mp[arr[j]]=1;
  for(ll j=0;j<MEX;j++){
  	if(!mp[j]){
  		cout<<"-1\n";
  		return;
  	}
  }
  cout<<"2\n";
  cout<<"1 "<<i+1<<"\n";
  cout<<i+2<<" "<<n<<endl;
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