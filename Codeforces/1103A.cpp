#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    string s;
    cin>>s;
    int r=0,c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            cout<<r+1<<" "<<"1"<<"\n";
            r+=2;
            r=r%4;
        }
        else
        {
            cout<<c+1<<" "<<"3"<<"\n";
            c++;
            c=c%4;
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
