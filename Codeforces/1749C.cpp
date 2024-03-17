#include <bits/stdc++.h>
using namespace std;

bool isPossible(int k, vector<int> &arr, int n)
{
    int index;
    for (index = n - 1; index >= 0; index--)
    {
        if (arr[index] <= k)
            break;
    }
    int comp=k;
    int distinct = 0;
    int x=k;
    for (int j = index; j >= k - 1; j--)
    {
        if (arr[j]<=x)
        {
            distinct++;
            x--;
        }
    }
    return (distinct >= k && (arr[k - 1] == 1));
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int ans = n; ans >= 0; ans--)
    {
        if (isPossible(ans, arr, n))
        {
            cout << ans << "\n";
            return;
        }
    }
    cout << "0\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    int count = 0;
    while (t--)
    {
        solve();
    }
    return 0;
}