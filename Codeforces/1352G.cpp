#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin >> n;
    if (n <= 3)
    {
        cout << "-1\n";
        return;
    }
    vector<ll> ans;
    ll l = 2, r = 1;
    while (l <= n || r <= n)
    {
        if (l <= n)
        {
            ans.push_back(l);
            l += 2;
        }
        if (l <= n)
        {
            ans.push_back(l);
            l += 2;
        }
        if (r <= n)
        {
            ans.push_back(r);
            r += 2;
        }
        if (r <= n)
        {
            ans.push_back(r);
            r += 2;
        }
    }
    if(n%4==2)
    {
        swap(ans[n-1],ans[n-3]);
        swap(ans[n-1],ans[n-2]);
    }
    else if(n%4==3)
    {
        swap(ans[n-1],ans[n-3]);
        swap(ans[n-4],ans[n-2]);
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout << "\n";
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
