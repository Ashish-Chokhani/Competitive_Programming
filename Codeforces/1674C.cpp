#include <bits/stdc++.h>
using namespace std;

long long int power(long long int a, long long int n)
{
    long long int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*a;
    }
    return ans;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    long long int l1 = s.length();
    long long int l2 = t.length();
    long long int flag = 0;
    for (long long int i = 0; i < l2; i++)
    {
        if (t[i] == 'a')
            flag = 1;
    }
    if (flag == 1 && l2 == 1)
    {
        cout << "1\n";
        return;
    }
    else if (flag == 1)
    {
        cout << "-1\n";
        return;
    }
    else
    {
        cout <<power(2,l1)<< "\n";
        return;
    }
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