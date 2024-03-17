#include<bits/stdc++.h>
using namespace std;

bool isPossible(int index,vector<int>&arr)
{
int n=arr.size();
if(n==0)
return true;
return (arr[n-1]-index)%2!=0; 
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>ans[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
    int color=arr[i];
    if(isPossible(i,ans[color]))
    ans[color].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i].size()<<" ";
    }
    cout<<"\n";
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