#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int l = s.length(), flag = 0;
    for (int i = 0; i < l; i++)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"-1\n";
        return;
    }
    for (int i = 0; i < l; i++)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            if (s[i] < s[l - 1])
            {
                char c = s[i];
                s[i] = s[l - 1];
                s[l - 1] = c;
                cout << s << "\n";
                return;
            }
        }
    }
    for (int i = l - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            char c = s[i];
            s[i] = s[l - 1];
            s[l - 1] = c;
            cout << s << "\n";
            return;
        }
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