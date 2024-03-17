#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll r=0,l=1e8+1;
    for(ll i=0;i<n-1;i++)
    {
        if(arr[i]<arr[i+1])
        l=min(l,((arr[i]+arr[i+1])/2));
        else if(arr[i]>arr[i+1])
        r=max(r,((arr[i]+arr[i+1]+1)/2));
    }
    if(l<r)
    {
        cout<<"-1\n";
        return;
    }
    else
    {
        cout<<r<<"\n";
    }
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