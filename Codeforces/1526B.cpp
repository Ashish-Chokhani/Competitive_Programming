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
    if (arr[0] <= arr[1])
    {
        cout << "YES\n";
        return;
    }
    if (n == 2)
    {
        cout << "NO\n";
        return;
    }
    bool isAscending=true,isDescending=true;
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            isDescending=false;
        }
        if (arr[i] >= arr[i + 1])
        {
            isAscending=false;
        }
    }
    if(!isAscending && !isDescending)
    cout<<"NO\n";
    else
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int cnt = 0;
    while (t--)
    {
        solve();
    }
    return 0;
}