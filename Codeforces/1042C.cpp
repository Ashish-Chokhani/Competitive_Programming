#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int negCnt = 0, maxi_neg = -1e9 - 6;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            negCnt++;
            maxi_neg = max(maxi_neg, arr[i]);
        }
    }
    vector<int> errors;
    int flag = 0;
    if (negCnt % 2 != 0)
        flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            errors.push_back(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((flag == 1) && (arr[i] == maxi_neg))
        {
            errors.push_back(i);
            break;
        }
    }
    int l = errors.size();
    int cnt = 0;
    for (int i = l - 1; i >= 1 && cnt <= n - 1; i--)
    {
        cout << "1 " << errors[i] + 1 << " " << errors[i - 1] + 1 << "\n";
        cnt++;
    }
    if (cnt < n - 1 && l >= 1)
    {
        cout << "2 " << errors[0] + 1 << "\n";
        cnt++;
    }
    vector<int> ans;
    if (l == 0)
        errors.push_back(n + 6);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0 && i != errors[l - 1])
            ans.push_back(i);
    }
    int x = ans.size();
    for (int i = 0; i < x - 1 && cnt <= n - 1; i++)
    {
        cout << "1 " << ans[i] + 1 << " " << ans[i + 1] + 1 << "\n";
        cnt++;
    }
}

int main()
{
    solve();
    return 0;
}
