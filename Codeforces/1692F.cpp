#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[i]=x%10;
    }
    vector<pair<int,pair<int,int>>> check;
    check.push_back({0,{0,3}});
    check.push_back({1,{1,1}});
    check.push_back({0,{1,2}});
    check.push_back({0,{4,9}});
    check.push_back({0,{5,8}});
    check.push_back({0,{6,7}});
    check.push_back({1,{4,8}});
    check.push_back({1,{3,9}});
    check.push_back({1,{5,7}});
    check.push_back({1,{6,6}});
    check.push_back({2,{2,9}});
    check.push_back({2,{4,7}});
    check.push_back({2,{8,3}});
    check.push_back({2,{5,6}});
    check.push_back({3,{4,6}});
    check.push_back({3,{5,5}});
    check.push_back({3,{3,7}});
    check.push_back({4,{5,4}});
    check.push_back({5,{9,9}});
    check.push_back({6,{8,9}});
    check.push_back({7,{7,9}});
    check.push_back({8,{8,7}});

    for(auto it : check)
    {
        int x=it.first;
        int y=it.second.first;
        int z=it.second.second;
        int flag_x=0,flag_y=0,flag_z=0;
        for(int i=0;i<n;i++)
        {
        if(arr[i]==x && flag_x==0)
        flag_x=1;
        else if(arr[i]==y && flag_y==0)
        flag_y=1;
        else if(arr[i]==z && flag_z==0)
        flag_z=1;
        }
        if(flag_x==1 && flag_y==1 && flag_z==1)
        {
        cout<<"YES\n";
        return;
        }
    }
    cout<<"NO\n";
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