#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> ans;
    if (n % 2 == 0)
    {
        cout << "-1\n";
        return;
    }
    while (n > 1)
    {
        if (((n - 1) / 2) % 2 == 1)
        {
            ans.push_back(2);
            n = (n - 1) / 2;
        }
        else
        {
            ans.push_back(1);
            n = (n + 1) / 2;
        }
    }
    cout<<ans.size()<<"\n";
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
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