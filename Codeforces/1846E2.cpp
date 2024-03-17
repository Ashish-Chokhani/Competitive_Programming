#include <bits/stdc++.h>
using namespace std;
 
typedef __int128 ll;
 
void solve()
{
    long long n;
    cin >> n;
    for (ll x = 2;x<=60; x++)
    {
        ll l = 2;
        ll r = 1e10;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll tot=1;
            ll flag=0;
            for(int i=1;i<=x+1;i++)
            {
                tot*=mid;
                if(tot>1e27)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                r=mid-1;
                continue;
            }
            ll val = (tot-1)/(mid-1);
            if (val == n)
            {
                cout << "YES\n";
                return;
            }
            if (val > n)
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    cout << "NO\n";
}
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}