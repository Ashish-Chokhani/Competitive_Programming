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
    vector<ll>suffix(n+2,0),maxi(n+1,0),prefix(n,0);
    prefix[0]=arr[0];
    for(ll i=1;i<n;i++)
    {
        prefix[i]=arr[i]+prefix[i-1];
    }
    suffix[n-1]=arr[n-1];
    for(ll i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]+arr[i];
    }
    maxi[n-1]=suffix[n-1];
    for(ll i=n-2;i>=0;i--)
    {
        maxi[i]=max(maxi[i+1],suffix[i]);
    }
    ll ans=0,val=0;
    for(ll i=0;i<n;i++)
    {
        if(max(0LL,maxi[i])>val)
        {
            val=max(0LL,maxi[i]);
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(max(0LL,prefix[i-1])+max(0LL,maxi[i])>=val)
        {
            ans=max(0LL,prefix[i-1]);
            val=max(0LL,prefix[i-1])+max(0LL,maxi[i]);
        }
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
    while(t--){
    solve();
    }
    return 0;
}