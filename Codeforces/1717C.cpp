#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, mini = 1e9 + 7,mini_index;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if(a[i]>b[i])
        {
            cout<<"NO\n";
            return;
        }
        if(b[i]<mini)
        mini_index=i;
        mini=min(mini,b[i]);

    }
    int curr_index=mini_index;
    for (int i = 0; i < n-1; i++)
    {
        int prev_index=curr_index-1;
        if(prev_index<0)
        prev_index=n-1;
        if(b[prev_index]>b[curr_index]+1 && a[prev_index]!=b[prev_index])
        {
        cout<<"NO\n";
        return;
        }
        curr_index=prev_index;
    }
    cout<<"YES\n";
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