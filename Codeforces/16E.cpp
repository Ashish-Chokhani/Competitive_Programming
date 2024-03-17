#include <bits/stdc++.h>
using namespace std;

int SetBits(int mask)
{
    int cnt = 0;
    while (mask > 0)
    {
        int b = mask & 1;
        cnt += (b == 1);
        mask = mask >> 1;
    }
    return cnt;
}

double pMove(int j, int prev_mask, vector<vector<double>> &prob, int n)
{
    int k = SetBits(prev_mask);
    double den = (k * (k - 1)) / 2;
    double ans=0;
    for (int fish = 0; fish < n; fish++)
    {
        if(prev_mask&(1<<fish))
        ans+=prob[fish][j];
    }
    return (double)ans/den;
}

vector<double> dp((1 << 18) + 2, -1);

double f(int mask, vector<vector<double>> &prob, int n)
{
    int setBits = SetBits(mask);
    if (setBits == n)
        return 1;
    if (dp[mask] != -1)
        return dp[mask];
    double ans = 0;
    for (int fish = 0; fish < n; fish++)
    {
        if (!(mask & (1 << fish)))
        {
            int prev_mask = mask ^ (1 << fish);
            double p = f(prev_mask, prob, n);
            ans += p * pMove(fish, prev_mask, prob, n);
        }
    }
    return dp[mask] = ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<double>> p(n, vector<double>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        cout <<setprecision(10)<< f(1<<i, p, n) << " ";
    cout << "\n";
}

int main()
{
    solve();
    return 0;
}