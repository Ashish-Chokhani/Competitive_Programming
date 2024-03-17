#include <bits/stdc++.h>
using namespace std;

bool containsA(string &s)
{
    for (long long int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
            return true;
    }
    return false;
}

bool containsB(string &s)
{
    for (long long int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'B')
            return true;
    }
    return false;
}

bool containsC(string &s)
{
    for (long long int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'C')
            return true;
    }
    return false;
}

long long int MinimumCost(vector<long long int> &arr, vector<string> &vitamins)
{
    long long int n = arr.size();
    long long int dp[n][2][2][2];
    for (long long int A = 0; A < 2; A++)
    {
        for (long long int B = 0; B < 2; B++)
        {
            for (long long int C = 0; C < 2; C++)
            {
                string s = vitamins[0];
                if ((!A && !containsA(s)) || (!B && !containsB(s)) || (!C && !containsC(s)))
                    dp[0][A][B][C] = 1e16;
                else
                    dp[0][A][B][C] = arr[0];
            }
        }
    }
    for (long long int index = 0; index < n; index++)
    {
        dp[index][1][1][1] = 0;
    }
    for (long long index = 1; index < n; index++)
    {
        for (long long int A = 0; A < 2; A++)
        {
            for (long long int B = 0; B < 2; B++)
            {
                for (long long int C = 0; C < 2; C++)
                {
                    string s = vitamins[index];
                    long long int pick = LONG_LONG_MAX;
                    if ((!A && containsA(s)) || (!B && containsB(s)) || (!C && containsC(s)))
                    {
                        pick = arr[index] + dp[index - 1][(A == 1) || containsA(s)][(B == 1) || containsB(s)][(C == 1) || containsC(s)];
                    }
                    long long int not_pick = dp[index - 1][A][B][C];
                    dp[index][A][B][C] = min(pick, not_pick);
                }
            }
        }
    }
    return dp[n-1][0][0][0];
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    vector<string> vitamins(n);
    map<char, long long int> mp;
    for (long long int i = 0; i < n; i++)
    {
        long long int x;
        string s;
        cin >> x >> s;
        arr[i] = x;
        vitamins[i] = s;
        if (containsA(s))
            mp['A'] = 1;
        if (containsB(s))
            mp['B'] = 1;
        if (containsC(s))
            mp['C'] = 1;
    }
    if (!mp['A'] || !mp['B'] || !mp['C'])
    {
        cout << "-1\n";
        return;
    }
    cout << MinimumCost(arr, vitamins) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}