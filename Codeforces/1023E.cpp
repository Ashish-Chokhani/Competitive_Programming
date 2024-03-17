#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    string top="",bot="",res;
    ll r=1,c=1;
    for(ll i=0;i<n-1;i++)
    {
        cout<<"? "<<r+1<<" "<<c<<" "<<n<<" "<<n<<"\n";
        cin>>res;
        if(res=="YES")
        {
            r++;
            top+='D';
        }
        else
        {
            c++;
            top+='R';
        }
    }
    r=n,c=n;
    for(ll i=0;i<n-1;i++)
    {
        cout<<"? "<<1<<" "<<1<<" "<<r<<" "<<c-1<<"\n";
        cin>>res;
        if(res=="YES")
        {
            c--;
            bot+='R';
        }
        else
        {
            r--;
            bot+='D';
        }
    }
    reverse(bot.begin(),bot.end());
    cout<<"! "<<top<<bot<<"\n";
}

int main()
{
    solve();
    return 0;
}
