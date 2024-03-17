#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    ll l = s.length();
    vector<char> ans(l);
    vector<ll> freq(26, 0);
    for (ll i = 0; i < l; i++)
    {
        freq[s[i] - 97]++;
    }
    ll p1 = 0, p2 = l - 1, i;
    for (i = 0; i < 26; i++)
    {
        if (!(freq[i] & 1))
        {
            while (freq[i] > 0)
            {
                ans[p1++] = char(i + 97);
                ans[p2--] = char(i + 97);
                freq[i] -= 2;
            }
        }
        else
        {
            while (freq[i] > 1)
            {
                ans[p1++] = char(i + 97);
                ans[p2--] = char(i + 97);
                freq[i] -= 2;
            }
            break;
        }
    }
    if (i < 26 && freq[i] == 1)
    {
        ll cnt = 0, start = -1;
        for (ll j = i + 1; j < 26; j++)
        {
            if (freq[j] != 0)
            {
                if (start == -1)
                    start = j;
                cnt++;
            }
        }
        if (cnt == 1)
        {
            while (freq[start] > 0)
            {
                ans[p1++] = char(start + 97);
                freq[start]--;
                if (freq[start] > 0)
                {
                    ans[p2--] = char(start + 97);
                    freq[start]--;
                }
            }
            ans[p1++] = char(i + 97);
        }
        else

            ans[p1++] = char(i + 97);
        for (ll j = i + 1; j < 26; j++)
        {
            while (freq[j] > 0)
            {
                freq[j]--;
                ans[p2--] = char(j + 97);
            }
        }
    }
    p1=0,p2=l-1;
    while(p1<p2)
    {
        if(ans[p1]!=ans[p2])
        {
            break;
        }
        p1++;
        p2--;
    }
    if(ans[p1]<ans[p2])
    reverse(ans.begin(),ans.end());
    for (auto it : ans)
        cout << it;
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
