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
  ll x,n;
  cin>>x>>n;
  vector<ll>arr(n);
  multiset<ll>intervals,cur_best;
  intervals.insert(0);
  intervals.insert(x);
  cur_best.insert(x);
  for(auto &point:arr){
    cin>>point;
    intervals.insert(point);
    auto it=intervals.find(point);
    auto temp1=it,temp2=it;
    auto left=--temp1;
    auto right=++temp2;
    ll l=point-*left;
    ll r=*right-point;
    cur_best.erase(cur_best.find(l+r));
    cur_best.insert(l);
    cur_best.insert(r);
    cout<<*(--cur_best.end())<<" ";
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