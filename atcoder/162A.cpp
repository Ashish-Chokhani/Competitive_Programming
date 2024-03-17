#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll>arr(n+1);
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        cnt+=arr[i]<=i;
    }
    cout<<cnt<<"\n";
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}