#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n),p(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    p[0]=arr[0];
    for(ll i=1;i<n;i++)
    {
        p[i]=arr[i]+p[i-1];
    }
    ll ans=0;
    for(ll front=0;front<=2*k;front++)
    {
        ll back_ind=n-1-(front/2);
        ll val=p[n-1]-p[back_ind];
        val+=p[n-1]-p[max(0,front-1)];
        ans=max(ans,val);
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
