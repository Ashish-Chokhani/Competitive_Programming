#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll g = arr[0];
    for (int i = 1; i < n; i++)
    {
        g = gcd(g, arr[i]);
    }
    if(g!=arr[0])
    {
        cout<<"-1\n";
        return;
    }
    cout<<(2*n-1)<<"\n";
    int flag=0;
    for (ll i = 0; i < n; i++)
    {
        if(flag%2!=0)
        {
        cout<<g<<" ";
        i--;
        }
        else
        cout<<arr[i]<<" ";
        flag++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
