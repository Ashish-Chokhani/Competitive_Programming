#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if (arr[n - 1] - arr[0] <= 1)
        cout << arr[n - 1] + 1 << "\n";
    else
        cout << arr[n - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
