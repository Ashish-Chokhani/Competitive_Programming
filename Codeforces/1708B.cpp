#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r,x;
    cin >> n >> l >> r;
    int county = 1;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        int rem=(l%i);
        if(rem!=0)
        x=l+(i-rem);
        else
        x=l;
        if((x>=l)&&(x<=r))
        {
        ans.push_back(x);
        }
        else
        {
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

    int main()
    {
        int t;
        cin >> t;
        int n,l,r;
        while (t--)
        {
            solve();
        }
        return 0;
    }