#include <bits/stdc++.h>
using namespace std;

long long int fun(long long int index, long long int blue, long long int green, vector<long long int> &arr, long long int h, long long int n)
{
    if (index >= n)
        return 0;
    if (arr[index] < h)
    {
        return 1 + fun(index + 1,blue, green, arr, h + (arr[index] / 2), n);
    }
    else
    {
        long long int pow1 = 0, pow2 = 0;
        if (blue == 0 && green == 0)
            return 0;
        if (blue > 0)
            pow1 = fun(index, blue - 1, green, arr, h * 3, n);
        if (green > 0)
            pow2 = fun(index, blue, green - 1, arr, h * 2, n);
        return max(pow1, pow2);
    }
}

void solve()
{
    long long int n, h, blue = 2, green = 1;
    cin >> n >> h;
    vector<long long int> arr(n), sum(n, 0);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout<<fun(0,1,2,arr,h,n)<<"\n";
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}