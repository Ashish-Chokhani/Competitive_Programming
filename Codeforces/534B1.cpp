#include <bits/stdc++.h>
using namespace std;
 
bool isPossible(long long int initial, long long int final, long long int d, long long int remtime)
{
    long long int mintime = ceil((double)abs((initial - final)) / d);
    return remtime >= mintime;
}
 
long long int findMaxDis(long long int currrentSpeed, long long int timeElapsed, long long int v1, long long int v2, long long int d, long long int t, vector<vector<long long int>> &dp)
{
    long long int timeleft = t - timeElapsed;
    if (timeleft == 0 || currrentSpeed<0)
        return 0;
    long long int in = LONG_LONG_MIN, de = LONG_LONG_MIN;
    if (dp[currrentSpeed][timeElapsed] != -1)
        return dp[currrentSpeed][timeElapsed];
    for (long long int increase = -d; increase <= d; increase++)
    {
        if (isPossible(currrentSpeed + increase, v2, d, t - (timeElapsed)))
        {
            in = max(in, currrentSpeed + increase + findMaxDis(currrentSpeed + increase, timeElapsed + 1, v1, v2, d, t, dp));
        }
    }
    return dp[currrentSpeed][timeElapsed] = in;
}
 
void solve()
{
    long long int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    long long int maxSpeed = 1000+max(v1,v2);
    vector<vector<long long int>> dp(maxSpeed+1, vector<long long int>(t+1, -1));
    cout << findMaxDis(v1, 2, v1, v2, d, t, dp) + v1 + v2 << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
