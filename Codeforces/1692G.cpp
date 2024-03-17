#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
    {
    cin>>arr[i];
    }
    int i=1,ans=0;
    while(i<n)
    {
    int count=1;
    while(i<n && ((double)arr[i]/arr[i+1])<2)
    {
    count++;
    i++;
    }
    i++;
    ans+=max(0,count-k);
    }
    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}