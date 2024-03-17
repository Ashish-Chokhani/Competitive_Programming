#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int twos = 0, threes = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] > 3)
        {
            cout << "NO\n";
            return;
        }
        else if (arr[i + 1] - arr[i] == 3)
            threes++;
        else if (arr[i + 1] - arr[i] == 2)
            twos++;
    }
    if (threes > 1 || twos > 2 || (threes == 1 && twos > 0))
        cout << "NO\n";
    else
        cout << "YES\n";
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