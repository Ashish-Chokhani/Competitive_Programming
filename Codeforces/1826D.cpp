#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n),left(n),right(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        left[i]=arr[i]+i;
        right[i]=arr[i]-i;
    }
    for(ll i=1;i<n;i++)
    {
        left[i]=max(left[i],left[i-1]);
    }
    for(ll i=n-2;i>=0;i--)
    {
        right[i]=max(right[i],right[i+1]);
    }
    ll ans=-1e9;
    for(ll i=1;i<n-1;i++)
    {
        ans=max(ans,arr[i]+left[i-1]+right[i+1]);
    }
    cout<<ans<<"\n";
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