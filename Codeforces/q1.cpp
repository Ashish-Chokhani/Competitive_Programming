#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int cnt_M=0,cnt_U=0;
    int flag=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='M')
        {
        cnt_M++;
        flag=1;
        }
        else if(s[i]=='U')
        {
        if(flag==1)
        cnt_U++;
        }
    }
    if (cnt_M>0 && cnt_U>0)
        cout << "Yes\n";
    else
       cout<<"No\n";
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
