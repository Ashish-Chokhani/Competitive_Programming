#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MaximumWindow(vector<ll> &V)
{
    ll n = V.size();
    ll maxi = 0, max_so_far = 0;
    for (ll i = 0; i < n; i++)
    {
        ll val = max_so_far + V[i];
        max_so_far = max(val, 0LL);
        maxi = max(maxi, max_so_far);
    }
    return maxi;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n),ans;
    ll maxi=-1e9,mini=1e9;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mini=min(mini,arr[i]);
        maxi=max(maxi,arr[i]);
    }
    sort(arr.begin(), arr.end());
    ll i = 0, j = n - 1;
    ll s = 0;
    while (i <= j)
    {
        if (s > 0)
        {
            ans.push_back(arr[i]);
            s += arr[i];
            i++;
        }
        else
        {
            ans.push_back(arr[j]);
            s += arr[j];
            j--;
        }
    }
    if(MaximumWindow(ans)>=maxi-mini)
    {
        cout<<"No\n";
    }
    else
    {
        cout<<"Yes\n";
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
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
