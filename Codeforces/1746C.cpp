#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>a(n+1,0);
    for(int i=0;i<n-1;i++)
    {
        a[i+2]=arr[i]-1;
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0)
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[i]!=0)
        cout<<mp[i]<<" ";
        else
        cout<<"1"<<" ";
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