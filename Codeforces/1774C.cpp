#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> dp(n - 1, 0);
    int lastOne=(s[0]=='1'),lastZero=(s[0]=='0'),index=0;
    for (int i = 2; i <=n; i++)
    {
        cout<<i-lastOne-lastZero<<" ";
        index++;
        if(s[index]=='1' && lastOne!=0)
        lastOne++;
        else if(s[index]=='0' && lastZero!=0)
        lastZero++;
        else
        {
            lastOne=0;
            lastZero=0;
            if(index<n-1)
            {
            lastOne=(s[index]=='1');
            lastZero=(s[index]=='0');
            }
        }
    }
    cout<<"\n";
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
