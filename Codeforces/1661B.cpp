#include <bits/stdc++.h>
using namespace std;

int Count2s(int n)
{
    int county = 0;
    while ((n & 1) == 0)
    {
        county++;
        n = n >> 1;
    }
    return county;
}

void solve(int n)
{
    int ans=20;
    for (int add = 0; add <= 15; add++)
    {
        int x = n+add;
        for(int multiply=0;multiply+add<=15;multiply++)
        {
            if(x%32768==0)
            {
                ans=min(ans,add+multiply);
                break;
            }
            x=x*2;
        }
    }
    cout<<ans<<" ";
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        solve(x);
    }
    cout<<"\n";
    return 0;
}