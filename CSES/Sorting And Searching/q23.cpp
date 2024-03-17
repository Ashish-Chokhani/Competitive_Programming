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

void solve(){
  ll n;
  cin>>n;
  vector<ll>arr(n);
  for(auto &x:arr){
    cin>>x;
  }
  stack<ll>st;
  vector<ll>ans(n,-1);
  st.push(0);
  for(ll i=1;i<n;i++){
    while(!st.empty() && arr[st.top()]>=arr[i]){
      st.pop();
    }
    if(!st.empty()){
      ans[i]=st.top();
    }
    st.push(i);
  }
  for(auto &x:ans){
    cout<<x+1<<" ";
  }
  cout<<"\n";
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