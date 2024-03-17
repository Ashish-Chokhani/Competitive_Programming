#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    long long int n = s.length();
    long long int count_b = 0, ans = 0;
    for (long long int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'b')
            count_b++;
        else
        {
            ans = (ans + count_b) % 1000000007;
            count_b = (count_b * 2) % 1000000007;
        }
    }
    cout << ans % 1000000007 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
