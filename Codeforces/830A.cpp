#include <bits/stdc++.h>
using namespace std;

long long int Sum(vector<long long int> &sum, long long int l, long long int r)
{
    if (l >= 1)
        return sum[r] - sum[l - 1];

    return sum[r];
}

long long int MinimumCost(long long int n,long long int k,long long int p,vector<long long int>&arr,vector<long long int>&b)
{
    long long int ans=LONG_LONG_MAX;
    for(long long int l=0;l<k-n+1;l++)
    {
        long long int j=l,ans1=0;
        for(long long int i=0;i<n;i++)
        {
            long long int cost=abs(arr[i]-b[j])+abs(b[j]-p);
            j++;
            ans1=max(ans1,cost);
        }
        ans=min(ans,ans1);
    }
    return ans;
} 

void solve()
{
    long long int n, k, p;
    cin >> n >>k>>p;
    vector<long long int> arr(n), b(k);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    for (long long int i = 0; i < k; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(),b.end());
    cout<<MinimumCost(n,k,p,arr,b)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
