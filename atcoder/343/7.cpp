#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
template<class T>void print(T x)
{
  cerr << x;
}
template<class T, class V>
         void print(pair<T , V> x)
{
  print(x.first); 
  cerr << ':';
  print(x.second);
}
template<class T>
         void print(vector<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T,
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T, 
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(unordered_set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T, class V>
         void print(vector<pair<T, V>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x.first);
    cerr << ":"; 
    print(x.second);
    cerr << ' ';
  }
  cerr << ']';
}
template <class T, class V> 
          void print(map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T, class V> 
          void print(unordered_map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T> 
          void print(vector<vector<T>> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template<class T>
         void print(stack<T> &a)
{
  cerr << '[' << ' ';
  stack<T>temp=a;
  while(!temp.empty())
  {
    auto val=temp.top();
    temp.pop();
    print(val); 
    cerr << " ";
  }
  cerr << ']';
}

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
  vector<string>s(n);
  for(ll i=0;i<n;i++){
  	cin>>s[i];
  }
  sort(s.begin(), s.end(),
        [&](string a,string b) {
            return a.size() < b.size();
        });
  vector<bool>isBadIndex(n+1,false);
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      if(j==i || isBadIndex[i] || isBadIndex[j]) continue;
      string t1=s[i];
      string t2=s[j];
      ll l1=t1.length(),l2=t2.length();
      if(l1>l2) continue;
      for(ll k=0;k+l1-1<l2;k++){
        if(t2.substr(k,l1)==t1){
          isBadIndex[i]=true;
          break;
        }
      }
    }
  }
  vector<string>new_s;
  for(ll i=0;i<n;i++){
    if(!isBadIndex[i]) new_s.push_back(s[i]);
  }
  s=new_s;
  n=s.size();
  auto computePi=[&](string &t){
    ll sz=t.length();
    vector<ll>pi(sz,0);
    ll j=0,i=1;
    while(i<sz){
      if(t[i]==t[j]){
        pi[i]=j+1;
        i++;
        j++;
      }
      else{
        while(j>0 && t[i]!=t[j]) j=pi[j-1];
        if(t[i]!=t[j]) i++;
      }
    }
    return pi;
  };
  vector<vector<ll>>g(n,vector<ll>(n,0));
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      if(i==j) continue;
      string t=s[j] + '#' + s[i];
      vector<ll>pi=computePi(t);
      ll sz=t.length();
      ll same=pi[sz-1];
      ll wt=s[j].length()-same;
      g[i][j]=wt;
    }
  }
  ll n2=1LL<<n;
  vector<vector<ll>>dp(n2,vector<ll>(n,INF));
  ll ans=INF;
  for(ll i=0;i<n;i++) dp[(1LL<<i)][i]=s[i].length();
  for(ll i=0;i<n2;i++) for(ll j=0;j<n;j++) {
    if(i>>j&1){
      for(ll k=0;k<n;k++){
        if(~i>>k&1) dp[i|(1LL<<k)][k]=min(dp[i|(1LL<<k)][k],dp[i][j]+g[j][k]);
      }
    }
  }
  for(ll i=0;i<n;i++) ans=min(ans,dp[n2-1][i]);
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