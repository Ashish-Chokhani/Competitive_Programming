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
    map<int,int>mp,last;
    for(int i=0;i<n;i++)
    {
    int num=arr[i];
    mp[num]-=i-last[num]+1;
    if(mp[num]<0)
    mp[num]=0;
    mp[num]++;
    last[num]=i;
    }
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