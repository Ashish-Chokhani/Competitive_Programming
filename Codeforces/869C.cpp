#include <bits/stdc++.h>
using namespace std;

const long long int p = 998244353;
vector<vector<long long int>> dp(5001,vector<long long int>(5001,-1));

long long int findWays(long long int x, long long int y)
{
    if (x <= 0 || y <= 0)
        return 1;
    if(dp[x][y]!=-1)
    return dp[x][y];
    long long int connect = (y * findWays(x - 1, y - 1))%p;
    long long int not_connect = findWays(x - 1, y)%p;
    return dp[x][y]=(connect + not_connect)%p;
}

void solve()
{
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int ans=(((findWays(a,b)*findWays(b,c))%p)*findWays(a,c))%p;
    cout<<ans%p<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
