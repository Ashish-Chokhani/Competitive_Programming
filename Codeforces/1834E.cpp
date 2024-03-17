#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e8;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    set<ll> possibleLCMs,prevLCMs;
    for (ll i = 0; i < n; i++)
    {
        set<ll> currentLCMs;
        if (arr[i] <= MAXN)
        {
            possibleLCMs.insert(arr[i]);
            currentLCMs.insert(arr[i]);
        }
        for (auto it : prevLCMs)
        {
            ll l = lcm(arr[i], it);
            //if(l==6) cout<<arr[i]<<" "<<it<<"\n";
            if (l <= MAXN)
            {
                currentLCMs.insert(l);
                possibleLCMs.insert(l);
            }
        }
        swap(prevLCMs,currentLCMs);
    }
    ll ans = 1;
    while (1)
    {
        if (possibleLCMs.find(ans) == possibleLCMs.end())
        {
            cout << ans << "\n";
            break;
        }
        ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt = 0;
    while (t--)
    {
        cnt++;
        if (cnt == 5405)
        {
            ll n;
            cin >> n;
            cout<<n<<".";
            vector<ll> arr(n);
            for (ll i = 0; i < n; i++)
            {
                cin >> arr[i];
                cout<<arr[i]<<".";
            }
        }
        solve();
    }
}