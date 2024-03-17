#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (!(n & 1))
    {
        ll val = k % n;
        if (val == 0)
            val = n;
        cout << val << "\n";
    }
    else
    {
        ll block = (n - 1) / 2;
        ll shift = (k - 1) / block;
        ll temp_ans = k%n;
        temp_ans+=shift;
        temp_ans=temp_ans%n;
        if(temp_ans==0)
        temp_ans=n;
        cout<<temp_ans<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    ll cnt=0;
    while (t--)
    {
        solve();
    }
    return 0;
}
