#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    int count_1 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            count_1++;
    }
    if (count_1 < s)
    {
        cout << "-1\n";
        return;
    }
    else if (count_1 == s)
    {
        cout << "0\n";
        return;
    }
    else
    {
        int i = 0, j = 0, len = -1, sum = 0;
        while (j < n)
        {
            sum += arr[j];
            if (sum < s)
            {
                j++;
            }
            else if (sum == s)
            {
                len = max(len, j - i + 1);
                j++;
            }
            else if (sum > s)
            {
                while (sum > s)
                {
                    sum -= arr[i];
                    i++;
                }
                if (sum == s)
                    len = max(len, j - i + 1);
                j++;
            }
        }
        cout << (n - len) << "\n";
    }
}

int main()
{
    int t, n, s;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}