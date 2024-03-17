#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void solve()
{
    long long int n,q;
    cin >> n >>q;
    vector<long long int> arr(n),arr1(n),k(q),sum(n,0);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr1[i];
        if(i>=1)
        arr[i]=max(arr1[i],arr[i-1]);
        else
        arr[i]=arr1[i];
    }
    sum[0]=arr1[0];
    for (long long int i = 1; i < n; i++)
    {
        sum[i]=arr1[i]+sum[i-1];
    }
    for (long long int i = 1; i <= q; i++)
    {
        cin >> k[i-1];
        long long int x=upper_bound(arr.begin(),arr.end(),k[i-1])-arr.begin();
        x--;
        if(x<0)
        cout<<"0 ";
        else
        cout<<sum[x]<<" ";
    }
    cout<<"\n";
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