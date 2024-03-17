#include <bits/stdc++.h>
using namespace std;

bool isPossible(int len, int k, vector<int> &arr, int n)
{
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == 0)
            cnt++;
    }
    if (cnt <= k)
        return true;
    int j = len, i = 0;
    while (j < n)
    {
        if (arr[i] == 0)
            cnt--;
        if (arr[j] == 0)
            cnt++;
        if (cnt <= k)
            return true;
        i++;
        j++;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr(n);
    map<pair<int,char>,int>mp;
    for (int j=97;j<=122;j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i]-j == 0)
                arr[i] = 1;
            else
                arr[i] = 0;
        }
        for (int k = 1; k <= n; k++)
        {
            int ans = 0, l = 1, r = n;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (isPossible(mid, k, arr, n))
                {
                    ans = max(ans, mid);
                    l = mid + 1;
                }
                else
                    r=mid-1;
            }
            mp[{k,(char)j}]=ans;
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        char c;
        cin>>x>>c;
        cout<<mp[{x,c}]<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
