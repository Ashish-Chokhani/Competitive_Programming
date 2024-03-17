#include <bits/stdc++.h>
using namespace std;

bool isEven(long long int a)
{
    return a % 2 == 0;
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<pair<long long int, long long int>> ans;
    if (arr[0] % 2 == 0)
    {
        long long int even_index = -1, even = 1e9 + 7;
        for (long long int i = n - 1; i >= 0; i--)
        {
            if (isEven(arr[i]))
            {
                if (even_index == -1 || arr[i] < even)
                {
                    even_index = i;
                    even = arr[i];
                }
                else if (arr[i] > even)
                {
                    ans.push_back({i, even_index});
                    arr[i] = arr[even_index];
                }
            }
        }
        for (long long int i = 0; i < n - 1; i++)
        {
            if (!isEven(arr[i + 1]))
            {
                arr[i + 1] = arr[i];
                ans.push_back({i, i + 1});
            }
        }
    }
    else
    {
        long long int odd_index = -1, odd = 1e9 + 7;
        for (long long int i = n - 1; i >= 0; i--)
        {
            if (!isEven(arr[i]))
            {
                if (odd_index == -1 || arr[i] < odd)
                {
                    odd_index = i;
                    odd = arr[i];
                }
                else if (arr[i] > odd)
                {
                    ans.push_back({i, odd_index});
                    arr[i] = arr[odd_index];
                }
            }
        }
        for (long long int i = 0; i < n - 1; i++)
        {
            if (isEven(arr[i + 1]))
            {
                arr[i + 1] = arr[i];
                ans.push_back({i, i + 1});
            }
        }
    }
    cout << ans.size() << "\n";
    for (long long int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
}

int main()
{
    long long int t, n;
    cin >> t;
    int count = 0;
    while (t--)
    {
        solve();
    }
    return 0;
}

// count++;
//         if (count == 127)
//         {
//             cin >> n;
//             vector<int> arr(n);
//             for (int i = 0; i < n; i++)
//             {
//                 cin >> arr[i];
//             }
//             cout << n << '.';
//             for (int i = 0; i < n; i++)
//             {
//                 cout << arr[i] << '.';
//             }
//         }