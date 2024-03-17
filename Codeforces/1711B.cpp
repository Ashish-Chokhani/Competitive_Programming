#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int>indegree(n,0);
    vector<pair<int,int>> friends;
    for(int i=0;i<m;i++)
    {
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    friends.push_back({x,y});
    indegree[x]++; 
    indegree[y]++;
    }
    if(m%2 == 0)
    {
        cout<<"0\n";
        return;
    }
    int ans1=1e9,ans2=1e9;
    for(int i=0;i<n;i++)
    {
        if(indegree[i] %2 !=0)
        {
            ans1=min(ans1,a[i]);
        }
    }
    for(auto it:friends)
    {
        if(indegree[it.first]%2==0 && indegree[it.second]%2==0)
        {
            ans2=min(ans2,a[it.first]+a[it.second]);
        }
    }
    cout<<min(ans1,ans2)<<"\n";
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