#include<bits/stdc++.h>
using namespace std;

bool isPossibleToLeave(long long int index,long long int county,long long int n)
{
    if(n%2!=0)
    return false;
    return county==0;
}

long long int fun(long long int index,long long int county,vector<long long int> & arr,long long int n,vector<vector<long long int>>&dp)
{
    if((index>=n-1)||(index<=0))
    return 0;

    if(dp[index][county]!=-1)
    return dp[index][county];

    long long int cost1=0,cost2=LONG_LONG_MAX;
    
    cost1=max(arr[index+1],arr[index-1])+1-arr[index];
    if(cost1<0)
    cost1=0;
    
    cost1+=fun(index-2,county,arr,n,dp);

    if(isPossibleToLeave(index,county,n))
    {
    cost2=fun(index-1,1,arr,n,dp);
    }

    return dp[index][county]=min(cost1,cost2);
}

void solve()
{
    long long int n;
    cin>>n;
    vector<long long int>arr(n);
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<long long int>> dp(n,vector<long long int>(2,-1));
    cout<<fun(n-2,0,arr,n,dp)<<"\n";
}

int main()
{
    long long int t;
    cin>>t;
    while ((t--))
    {
        solve();
    }
    
    return 0;
}