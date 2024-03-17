#include <bits/stdc++.h>
using namespace std;

long long int countInversions(vector<long long int> &arr)
{
    long long int county=0,county_zero=0;
    long long int n=arr.size();
    for(long long int i=0;i<n;i++)
    {
        if(arr[i]==0)
        county_zero++;
    }
    for(long long int i=0;i<n;i++)
    {
        if(arr[i]==1)
        county+=county_zero;
        else
        county_zero--;
    }
    return county;
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long int>arr1(arr.begin(),arr.end());
    vector<long long int>arr2(arr.begin(),arr.end());
    for(long long int i=0;i<n;i++)
    {
        if(arr1[i]==0)
        {
            arr1[i]=1;
            break;
        }
    }
    for(long long int i=n-1;i>=0;i--)
    {
        if(arr2[i]==1)
        {
            arr2[i]=0;
            break;
        }
    }
    cout<<max(max(countInversions(arr1),countInversions(arr2)),countInversions(arr))<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}