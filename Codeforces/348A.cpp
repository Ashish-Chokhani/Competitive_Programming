#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll s=0;
    ll maxi=-1;
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
        s+=arr[i];
    }
    ll ans=(s+n-2)/(n-1);
     if(ans<maxi)
        ans=maxi;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}