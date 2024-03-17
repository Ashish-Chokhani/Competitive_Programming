#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve()
{
    ll n,m,x;
    cin>>n>>m>>x;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++)
    {
        ll y;
        cin>>y;
        arr[i]={y,i};
    }
    sort(arr.begin(),arr.end());
    multiset<pair<ll,ll>>mt;
    map<ll,ll>mp;
    for(ll i=0;i<m;i++)
    {
        mt.insert({arr[i].first,i});
        mp[arr[i].second]=i;
    }
    for(ll i=m;i<n;i++)
    {
        auto it=mt.begin();
        ll val=it->first;
        ll ind=it->second;
        mt.erase(it);
        mt.insert({arr[i].first+val,ind});
        mp[arr[i].second]=ind;
    }
    ll mini=1e10,maxi=0;
    for(auto it:mt)
    {
        mini=min(mini,it.first);
        maxi=max(maxi,it.first);
    }
    if(maxi-mini>x)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(ll i=0;i<n;i++)
    {
        cout<<mp[i]+1<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}