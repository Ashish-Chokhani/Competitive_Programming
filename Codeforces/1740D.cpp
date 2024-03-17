#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(k);
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    int capacity = (n * m) - 4;
    int search = k, curr = -1, acc =0;
    while (search >= 1)
    {
        int index = mp[search];
        if (index > curr)
        {
            acc += index - curr - 1;
            if (acc > capacity)
            {
                cout << "TIDAK\n";
                return;
            }
            curr = index;
        }
        else
        {
            acc--;
        }
        search--;
    }
    cout << "YA\n";
    return;
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