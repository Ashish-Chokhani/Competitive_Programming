#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), b(n, -1);
    vector<int> mp1(1e6 + 1, 0), mp2(1e6 + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp1[arr[i]] = i + 1;
    }

    queue<int> q;

    for (int i = 0; i <= 1e6; i++)
    {
        if (!mp1[i])
            q.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        if(i==0 || (i>=1 && arr[i-1]==arr[i]))
        {
            b[i]=q.front();
            q.pop();
        }
        else
        {
            b[i]=arr[i-1];
        }
        if (b[i] == -1)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}