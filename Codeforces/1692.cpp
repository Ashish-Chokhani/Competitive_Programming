#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> mp, last,start,end,s;
    int ans = 0, ans_a = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        mp[num] -= i - last[num];
        if(s[num]==0)
        s[num]=i+1;
        if(end[num]==0)
        end[num]=i+1;
        if (mp[num] < 0)
        {
            mp[num] = 0;
            s[num]=i+1;
        }
        mp[num]++;
        last[num] = i+1;
        if (mp[num] > ans)
        {
            ans = mp[num];
            ans_a = num;
            start[num]=s[num];
            end[num]=i+1;
        }
    }
    cout << ans_a <<" "<<start[ans_a]<<" "<<end[ans_a]<< "\n";
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