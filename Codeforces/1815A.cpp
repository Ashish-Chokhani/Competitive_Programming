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
    for (ll i = 1; i < n-1; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            ll val = arr[i - 1] - arr[i];
            arr[i]+=val;
            if (i + 1 < n)
                arr[i + 1] += val;
        }
        else
        {
            ll val = arr[i] - arr[i - 1];
            arr[i]-=val;
            if (i + 1 < n)
                arr[i + 1] -= val;
        }
    }
    if (arr[n - 1] < arr[n - 2])
    {
        if (n % 2 == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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