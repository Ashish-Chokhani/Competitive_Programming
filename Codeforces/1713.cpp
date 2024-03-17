#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    int no = sqrt((2 * n) - 2);
    vector<int> check(n, 0);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = (no * no) - arr[i];
        if (!check[x] && (x < n))
        {
            ans.push_back(x);
            check[x] = 1;
        }
        else
        {
            while (1)
            {
                no--;
                if (no < 0)
                {
                    cout << "-1\n";
                    return;
                }
                int y = (no * no) - arr[i];
                if (!check[y])
                {
                    ans.push_back(y);
                    check[y] = 1;
                    break;
                }
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
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