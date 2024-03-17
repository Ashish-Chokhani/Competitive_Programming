#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<vector<long long int>> arr(n, vector<long long int>(n));
    long long int sum = 0, mini = 1e9 + 7;
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];
            if (i+j==n-1)
            {
                mini = min(mini, arr[i][j]);
            }
        }
    }
    cout << sum - mini << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}