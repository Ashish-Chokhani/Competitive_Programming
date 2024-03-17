#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<double>>> dp(302, vector<vector<double>>(302, vector<double>(302, -1)));

double Sushi(int CountOnes, int CountTwos, int CountThrees, int n)
{
    if ((CountOnes + CountTwos + CountThrees) == 0)
        return 0;
    if (dp[CountOnes][CountTwos][CountThrees] != -1)
        return dp[CountOnes][CountTwos][CountThrees];
    int cnt = 0;
    double x = 0, y = 0, z = 0;
    if (CountOnes >= 1)
    {
        cnt++;
        x = Sushi(CountOnes - 1, CountTwos, CountThrees, n);
    }
    if (CountTwos >= 1)
    {
        cnt++;
        y = Sushi(CountOnes + 1, CountTwos - 1, CountThrees, n);
    }
    if (CountThrees >= 1)
    {
        cnt++;
        z = Sushi(CountOnes, CountTwos + 1, CountThrees - 1, n);
    }
    double p = 1+(x*((double)CountOnes/n))+((y*((double)CountTwos/n)))+((z*((double)CountThrees)/n));
    double r = (double)(CountOnes + CountTwos + CountThrees)/n;
    return dp[CountOnes][CountTwos][CountThrees] = (double)p/r;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int CountOnes = 0, CountTwos = 0, CountThrees = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        CountOnes += (arr[i] == 1);
        CountTwos += (arr[i] == 2);
        CountThrees += (arr[i] == 3);
    }
    cout <<setprecision(12)<<Sushi(CountOnes, CountTwos, CountThrees, n) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}