#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
            arr[i] = 1;
        else
            arr[i] = 0;
    }
    int maxi = 0, sum = 0;
    int j = 0;
    while (j < k)
    {
        sum += arr[j];
        j++;
    }
    maxi = max(sum, maxi);
    for (int i = k; i < n; i++)
    {
        sum-=arr[i-k];
        sum+=arr[i];
        maxi = max(sum, maxi);
    }
    cout << (k - maxi) << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}