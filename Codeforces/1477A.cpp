#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long int a, long long int Tn, long long int d)
{
    long long int x = Tn - a;
    x = abs(x);
    return (x % d == 0);
}

void solve()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<long long int> diff;
    for (long long int i = 1; i < n; i++)
    {
        diff.push_back(arr[i] - arr[i - 1]);
    }
    long long int g = diff[0];
    for (long long int i = 1; i < diff.size(); i++)
    {
        g = gcd(g,diff[i]);
    }
    for(long long int i=0;i<n;i++)
    {
        if(isPossible(arr[i],k,g))
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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