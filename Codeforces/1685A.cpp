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
    sort(arr.begin(), arr.end());
    vector<int> ans;
    if (n % 2 != 0)
    {
        cout << "NO\n";
        return;
    }
    int i = 0;
    while (i <= (n/2-1))
    {
        ans.push_back(arr[i]);
        ans.push_back(arr[i+(n/2)]);
        i++;
    }
    if (!((ans[0] > ans[1] && ans[0] > ans[n - 1]) || (ans[0] < ans[1] && ans[0] < ans[n - 1])))
    {
        cout << "NO\n";
        return;
    }
    if (!((ans[n - 1] > ans[n - 2] && ans[n - 1] > ans[0]) || (ans[n - 1] < ans[n - 2] && ans[n - 1] < ans[0])))
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (!((ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) || (ans[i] < ans[i - 1] && ans[i] < ans[i + 1])))
        {
            cout << "NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int t,n;
    cin >> t;
    int count=0;
    while(t--)
    {
        solve();
    }
    return 0;
}