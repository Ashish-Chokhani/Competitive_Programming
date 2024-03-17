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

vector<ll>arr;
vector<ll>nse,pse;
ll n;

void getPrevSmaller(){
	stack<ll>st;
	st.push(0);
	fill(pse.begin(),pse.end(),-1);
	for(ll i=1;i<n;i++){
		while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
		if(!st.empty()) pse[i]=st.top();
		st.push(i);
	}
}

void getNextSmaller(){
	stack<ll>st;
	st.push(n-1);
	fill(nse.begin(),nse.end(),n);
	for(ll i=n-2;i>=0;i--){
		while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
		if(!st.empty()) nse[i]=st.top();
		st.push(i);
	}
}
 
void solve(){
  cin>>n;
  arr.resize(n);
  nse.resize(n);
  pse.resize(n);
  ll cntZeros=0;
  for(ll &x:arr){
  	cin>>x;
  	cntZeros+=(x==0);
  }
  if(cntZeros!=1){
  	cout<<"NO\n";
  	return;
  }
  getNextSmaller();
  getPrevSmaller();
  for(ll i=0;i<n;i++){
  	if(arr[i]==0) continue;
  	bool ok=false;
  	ok=pse[i]!=-1 && arr[pse[i]]==arr[i]-1;
  	ok|=nse[i]!=n && arr[nse[i]]==arr[i]-1;
  	if(!ok){
  		cout<<"NO\n";
  		return;
  	}
  }
  cout<<"YES\n";
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