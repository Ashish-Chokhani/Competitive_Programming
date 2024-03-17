#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, m;
    cin >> n >> m;
    long long int x = n / m;
    long long int rem = n % m;
    long long int ans1 = (rem*(x+1)*x)/2 + ((m-rem)*x*(x-1)/2);
    long long int ans2 = (n - m + 1) * (n - m) / 2;
    cout << ans1 << " " << ans2 << "\n";
}

int main()
{
    solve();
    return 0;
}