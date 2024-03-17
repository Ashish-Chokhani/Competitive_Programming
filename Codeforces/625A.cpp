#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

void solve()
{
    long long int n, a, b, c;
    cin >> n >> a >> b >> c;
    if ((n < a) && (n < b))
    {
        cout << "0\n";
        return;
    }
    if ((a <= b - c) || (n < b))
    {
        cout << n / a;
        return;
    }
    long long int ans = 1;
    long long int x = (n - b) / (b - c);
    ans += x;
    long long int l = (n - (ans * (b - c))) / a;
    if (l > 0)
        ans += l;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
