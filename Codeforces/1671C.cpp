#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,x;
    cin>>n>>x;
    vector<long long int>arr(n);
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<long long int>sum(n,0);
    sum[0]=arr[0];
    for(long long int i=1;i<n;i++)
    {
        sum[i]=arr[i]+sum[i-1];
    }
    long long int last_index=upper_bound(sum.begin(),sum.end(),x)-sum.begin();
    last_index--;
    long long int ans=0;
    for(long long int i=0;i<=last_index;i++)
    {
        long long int days=(x-sum[i])/(i+1)+1;
        ans+=days;
    }
    cout<<ans<<"\n";
}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}