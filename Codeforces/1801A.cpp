#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    cout<<(n*m)<<"\n";
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
           cout<<(i+1)+j*1024<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  while(t--)
  {
  solve();
  }
}