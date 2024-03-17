#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n + 1);
    map<int, int> mp;
    arr[1] = x;
    mp[x] = 1;
    arr[n] = 1;
    mp[1] = 1;
    for (int i = 2; i <= n - 1; i++)
    {
        if (mp[i] == 0)
        {
            arr[i] = i;
            mp[i] = 1;
        }
        else
        {
            int mul = 2, flag = 0;
            while (mul * i <= n)
            {
                if (!mp[mul * i] && (n % (mul*i)==0))
                {
                    arr[i] = mul * i;
                    mp[mul * i] = 1;
                    flag = 1;
                    break;
                }
                mul++;
            }
            if (!flag)
            {
                cout << "-1\n";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}