#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    int maxi = 0,maxi_freq=0;
    if (n % k == 0)
    {
        maxi_freq = k;
        maxi=n/k;
    }
    else
    {
        maxi_freq=n%k;
        maxi = (n/k)+1;
    }
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(arr[i]==maxi)
        cnt++;
        if(cnt>maxi_freq || arr[i]>maxi)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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
