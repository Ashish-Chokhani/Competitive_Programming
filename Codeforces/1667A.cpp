#include <bits/stdc++.h>
using namespace std;

long long int findOperations(long long int ai, long long int k)
{
    double x=(double)k/ai;
    return ceil(x);
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
    long long int ans = LONG_LONG_MAX;
    for (long long int pivot = 0; pivot <n; pivot++)
    {
        long long int county = 0,prev=0;
        for (long long int left = pivot - 1; left >= 0; left--)
        {
            long long int op=findOperations(arr[left],prev+1);
            prev=op*arr[left];
            county+=op;
        }
        prev=0;
        for (long long int right = pivot + 1; right < n; right++)
        {
            long long int op=findOperations(arr[right],prev+1);
            prev=op*arr[right];
            county+=op;
        }
        ans=min(ans,county);
    }
    cout<<ans<<"\n";
}

int main()
{
    solve();
    return 0;
}