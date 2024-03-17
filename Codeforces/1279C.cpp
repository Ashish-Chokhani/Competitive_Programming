#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    map<ll,ll>mp;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]=i;
    }
    for(ll i=0;i<m;i++)
    {
        cin>>b[i];
    }
    ll ans=m;
    ll maxi=0;
    for(ll i=0;i<m;i++)
    {
        ll ind=mp[b[i]];
        if(ind>maxi)
        {
            ans+=(ind-i)*2;
        }
        maxi=max(maxi,ind);
    }
    cout<<ans<<"\n";
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