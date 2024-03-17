#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n), V;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < (i + 1))
        {
            V.push_back(arr[i]);
        }
    }
    sort(V.begin(), V.end());
    if (V.size() == 0)
    {
        cout << "0\n";
        return;
    }
    long long int mini = V[0], county = 0;
    for (long long int i = 1; i <= n - 2; i++)
    {
        if ((arr[i - 1] < i) && (i > mini))
        {
            long long int x = upper_bound(V.begin(), V.end(), i) - V.begin();
            if (x == V.size())
            {
                cout << county << "\n";
                return;
            }
            county += V.size() - x;
        }
    }
    cout << county << "\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}