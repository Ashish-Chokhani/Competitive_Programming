#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n,m;
    cin>>n>>m;
    vector<long long int> arr1(n),arr2(m);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (long long int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    long long int ans=0;
    for (long long int i = 0; i < n; i++)
    { 
        int index1=lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
        int index2=upper_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
        if(arr2[index1]!=arr1[i])
        index1--;
        long long int ans1=INT_MAX,ans2=INT_MAX;
        if(index1!=m && index1>=0)
        ans1=abs(arr2[index1]-arr1[i]);
        if(index2!=m && index2>=0)
        ans2=abs(arr2[index2]-arr1[i]);
        ans=max(ans,min(ans1,ans2));
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}