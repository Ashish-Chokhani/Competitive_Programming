#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N = 1000001;
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> freq(N, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    for (int i = 2; i < N; i++)
    {
        if (freq[i] > freq[i - 1])
        {
            cout << "-1\n";
            return;
        }
    }
    cout<<freq[1]<<"\n";
    vector<int> ans(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        ans[i] = ++mp[arr[i]];
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
