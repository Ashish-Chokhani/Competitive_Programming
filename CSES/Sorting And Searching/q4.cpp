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
  ll n,m;
  cin>>n>>m;
  vector<ll>desired(n),available(m);
  for(auto &num:desired){
    cin>>num;
  }
  for(auto &num:available){
    cin>>num;
  }
  multiset<ll>st;
  for(auto &num:desired){
    st.insert(num);
  }
  for(auto &price:available){
    if(st.empty()){
      cout<<"-1 ";
      continue;
    }
    auto it=st.lower_bound(price);
    if(it!=st.end() && *it==price){
      cout<<price<<" ";
      st.erase(it);
      continue;
    }
    if(it==st.begin()){
      cout<<"-1 ";
      continue;
    }
    --it;
    if(*it<=price){
      cout<<*it<<" ";
      st.erase(it);
      continue;
    }
    cout<<"-1 ";
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
    
    solve();
    return 0;
}