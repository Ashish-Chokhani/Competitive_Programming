#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    map<long long int, long long int> last_index;
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        last_index[arr[i]] = i;
    }
    long long int i = 0;
    long long int ans = 1;
    while (i < n)
    {
        long long int maxi = last_index[arr[i]];
        while (i <= maxi)
        {
            if (last_index[arr[i]] > maxi)
                maxi = last_index[arr[i]];
            i++;
        }
        if(i<n)
        ans=(ans*2)%MOD;
    }
    cout<<ans%MOD<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}