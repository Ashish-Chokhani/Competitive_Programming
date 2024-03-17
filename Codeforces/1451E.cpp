#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n;
    cin >> n;
    ll y1, y2, y3, y4, y5, y6;
    cout << "XOR 1 2"<<endl;
    cin >> y1;
    cout << "XOR 2 3"<<endl;
    cin >> y2;
    y3 = y1 ^ y2;
    cout << "AND 1 2"<<endl;
    cin >> y4;
    cout << "AND 2 3"<<endl;
    cin >> y5;
    cout << "AND 1 3"<<endl;
    cin >> y6;
    ll a2 = 0;
    for (ll bit = 0; bit < 16; bit++)
    {
        if (!((y1 >> bit) & 1))
        {
            if ((y4 >> bit) & 1)
                a2 = a2 | (1 << bit);
        }
        else
        {
            if (!((y2 >> bit) & 1))
            {
                if ((y5 >> bit) & 1)
                    a2 = a2 | (1 << bit);
            }
            else if (!((y6 >> bit) & 1))
            {
                a2 = a2 | (1 << bit);
            }
        }
    } 
    vector<ll> ans(n);
    ans[0] = a2 ^ y1;
    ans[1] = a2;
    ans[2] = a2 ^ y2;
    for (ll i = 4; i <= n; i++)
    {
        ll y;
        cout << "XOR 2 "<<i<<endl;
        cin >> y;
        ans[i-1]=y^a2;
    }
    cout<<"! ";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}