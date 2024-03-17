#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<long long int> arr(n);
    long long int ans = 0, last_1 = -1, last_0 = -1, first_1 = -1, first_0 = -1,flag=0;
    for (long long int i = 0; i < n; i++)
    {
        arr[i] = s[i] - '0';
        if (arr[i] == 1)
        {
            last_1 = i;
            if (first_1 == -1)
                first_1 = i;
        }
        if (arr[i] == 0)
        {
            last_0 = i;
            if (first_0 == -1)
                first_0 = i;
        }
        if (i >= 1)
        {
            ans += (arr[i - 1] * 10) + arr[i];
        }
    }
    if (k == 0)
    {
        cout << ans << "\n";
        return;
    }
    else if (n == 2 && arr[0] == 1 && arr[1] == 0)
        ans -= 9;
    else if (n > 2)
    {
        if (arr[n - 1] == 0)
        {
            if (last_1 != -1 && (n - 1 - last_1) <= k)
            {
                ans -= 10;
                k -= n - 1 - last_1;
                flag=1;
            }
        }
        if (arr[0] == 0)
        {
            if (first_1 != -1 && first_1 <= k)
            {
                if((flag==0 && arr[n-1]!=1) || first_1!=last_1)
                ans -= 1;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    long long int t, n, k,x;
    cin >> t;
    //int count = 0;
    //x=t;
    while (t--)
    {
        solve();
    }
    return 0;
}