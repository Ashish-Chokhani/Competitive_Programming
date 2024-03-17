#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> dp(102, vector<long long int>(100002, -1));

long long int findMiniWeight(long long int index, long long int sum, vector<long long int> &W, vector<long long int> &v)
{
    if (sum < 0)
        return 1e17;
    if (sum == 0)
        return 0;
    if (index < 0)
        return 1e17;
    if (dp[index][sum] != -1)
        return dp[index][sum];
    long long int pick = 1e15, not_pick = 1e15;
    if (v[index] <= sum)
        pick = W[index] + findMiniWeight(index - 1, sum - v[index], W, v);
    not_pick = findMiniWeight(index - 1, sum, W, v);
    return dp[index][sum] = min(pick, not_pick);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n,W;
    cin>>n>>W;
    vector<long long int>v(n),w(n);
    for(long long int i=0;i<n;i++)
    {
        long long int x,y;
        cin>>x>>y;
        w[i]=x;
        v[i]=y;
    }
    long long int ans=0;
    for(long long int val=1;val<=100000;val++)
    {
        if(findMiniWeight(n-1,val,w,v)<=W)
        ans=val;
    }
    cout<<ans<<"\n";
}
