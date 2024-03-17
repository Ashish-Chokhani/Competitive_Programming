#include <bits/stdc++.h>
using namespace std;

int fun(int index,vector<int> &arr)
{
    if(index==0)
    return;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (s[i] == '>');
    }
    cout<<fun(n-1,arr)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}