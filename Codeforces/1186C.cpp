#include <bits/stdc++.h>
using namespace std;

bool isSame(long long int a, long long int b)
{
    return (((a % 2) == 0) && ((b % 2) == 0) || ((a % 2) != 0) && ((b % 2) != 0));
}

void solve()
{
    string a, b;
    cin >> a >> b;
    long long int l1 = a.length(), l2 = b.length();
    long long int aOnes = 0, bOnes = 0, ans = 0;
    for (long long int i = 0; i < l2; i++)
    {
        if (a[i] == '1')
            aOnes++;
        if (b[i] == '1')
            bOnes++;
    }
    if (isSame(aOnes, bOnes))
        ans++;
    long long int j = l2, i = 1;
    while (j < l1)
    {
        if (a[i - 1] == '1')
            aOnes--;
        if (a[j] == '1')
            aOnes++;
        if (isSame(aOnes, bOnes))
            ans++;
        i++;
        j++;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}