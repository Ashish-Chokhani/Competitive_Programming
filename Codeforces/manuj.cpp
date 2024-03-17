#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define M 100000007
#define f_(i, j, n) for (ll i = j; i <= n; i++)
#define f__(i, j, n) for (ll i = j; i >= n; i--)
#define endl '\n'

void solve()
{
  ll n,l,r;
  cin>>n>>l>>r;
  // output the answers
  vector<ll> ans;
  for(int i=1;i<=n;i++){
    if(l%i==0) ans.push_back(l);
    else ans.push_back(((l/i)+1)*i);
  }
  for(int i=0;i<n;i++){
    if(ans[i]<l || ans[i]>r){
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
  for(auto x:ans) cout<<x<<' ';
  cout<<endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}