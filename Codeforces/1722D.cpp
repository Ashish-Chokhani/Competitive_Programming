#include <bits/stdc++.h>
using namespace std;

bool isProfitable(long long int n, long long int val, long long int ind, char ch)
{
    if (ch == 'L')
        return (n - 1 - ind) > val;
    else
        return ind > val;
}

void solve()
{
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<long long int, long long int>> arr;
    long long int val = 0;
    for (long long int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            arr.push_back({i, i});
            val += i;
        }
        else
        {
            arr.push_back({n - 1 - i, i});
            val += n - 1 - i;
        }
    }
    sort(arr.begin(), arr.end());
    for (auto it : arr)
    {
        if (isProfitable(n, it.first, it.second, s[it.second]))
        {
            if (s[it.second] == 'L')
            {
                s[it.second] = 'R';
                val = val - it.first;
                val += n - 1 - it.second;
            }
            else
            {
                s[it.second] = 'L';
                val = val - it.first;
                val += it.second;
            }
        }
        cout<<val<<" ";
    }
    cout<<"\n";
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