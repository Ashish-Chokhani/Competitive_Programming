#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,k,m;
    cin >> n>>k>>m;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int maxi=0,type=-1;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
    int rem=arr[i]%m;
    mp[rem]++;
    if(mp[rem]>maxi)
    {
        maxi=mp[rem];
        type=rem;
    }
    }
    if(maxi<k)
    {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    for(int i=0;i<n && k>0;i++)
    {
        if(arr[i]%m==type)
        {
            cout<<arr[i]<<" ";
            k--;
        }
    }
    cout<<"\n";
}

int main()
{
    solve();
    return 0;
}
