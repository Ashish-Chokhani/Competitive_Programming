#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n, l1 = 0, l2 = 0, flag1 = 0, flag2 = 0;
    cin >> n;
    for (long long int i = 1; i <= n; i++)
    {
        long long int type, freq, x1 = 0, x2 = 0;
        string s;
        cin >> type >> freq;
        cin >> s;
        if (type == 1)
            x1 = s.length();
        else
            x2 = s.length();
        l1 += (x1*freq);
        l2 += (x2*freq);
        if (type == 2)
        {
            for (long long int i = 0; i < x2; i++)
            {
                if (s[i] != 'a')
                    flag2 = 1;
            }
        }
        if (flag2)
        {
            cout << "YES\n";
            continue;
        }
        if (type == 1)
        {
            if (flag1 == 0)
            {
                for (long long int i = 0; i < x1;i++)
                {
                    if(s[i]!='a')
                    {
                        flag1=1;
                        break;
                    }
                }
            }
        }
        if(flag1==0 && l1<l2)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}