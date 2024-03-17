#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll findSx(ll s, ll x)
{
    return s+x*20;
}

void solve()
{
    ll s, k;
    cin >> s >> k;
    // for 5 and 10 handle
    ll ans = s * k;
    s+=s%10;
    k--;
    ans=max(ans,s*k);
    if(s%5==0){
        cout<<ans<<"\n";
        return;
    }
    for (int i = 0; i < 4 && k>0; i++)
    {
        int l = 0, r = k;
        while (l <= r)
        {
            ll x = (l + r) / 2;
            ll left = findSx(s, x) * (k - 4*x);
            ll right = findSx(s, x + 1) * (k - 4*(x+1));
            if (left < right)
                l = x + 1;
            else
                r = x-1;
        }
        ans=max(ans,(s+(l*20LL))*(k-(4LL*l)));
        s+=s%10;
        k--;
    }
    cout << ans << "\n";
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