#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            int temp = i;
            while (i < n && s[i] == '0')
            {
                i++;
            }
            maxi += (i - temp) / b;
        }
    }
    int fake = maxi - a;
    int ans = fake + 1;
    int count = ans;
    vector<int> arr;
    for (int i = 0; i < n && count > 0; i++)
    {
        if (s[i] == '0')
        {
            int temp = i;
            int len=1;
            while (i < n && s[i] == '0')
            {
                if (len==b)
                {
                    arr.push_back(i+1);
                    count--;
                    break;
                }
                len++;
                i++;
            }
        }
    }
    cout << ans << "\n";
    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
