#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        arr[i]={x,i};
    }
    sort(arr.begin(),arr.end());
    vector<ll>first,second;
    for(ll i=0;i<n;i++)
    {
        if(!(i&1))
        first.push_back(arr[i].second);
        else
        second.push_back(arr[i].second);
    }
    cout<<first.size()<<"\n";
    for(auto it:first)
    cout<<it+1<<" ";
    cout<<"\n";
    cout<<second.size()<<"\n";
    for(auto it:second)
    cout<<it+1<<" ";
    cout<<"\n";


}

int main()
{
    solve();
    return 0;
}