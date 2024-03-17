#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<ll>> fun(ll a, ll b)
{
    vector<vector<ll>> arr(25, vector<ll>(50, -1));
    ll n = ceil((double)b / 13);
    n = ceil(n);
    ll cnt_b = b-1;
    for (ll col = 0; col < (2 * n) - 1 && col < 50; col++)
    {
        for (ll row = 0; row < 25; row++)
        {
            if (cnt_b > 0 && row % 2 == 0 && col % 2 == 0)
            {
                arr[row][col] = 1;
                cnt_b--;
            }
            else
                arr[row][col] = 0;
        }
    }
    for (ll row = 0; row < 25; row++)
    {
        arr[row][(2 * n) - 1] = 0;
    }
    for (ll row = 0; row < 25; row++)
    {
        arr[row][(2 * n)] = 1;
    }
    ll cnt_a = a - 1, flag = 0;
    for (ll col = (2 * n)+1; col < 50; col++)
    {
        for (ll row = 0; row < 25; row++)
        {
            if (cnt_a > 0 && row % 2 == 0 && flag % 2 == 0)
            {
                arr[row][col] = 0;
                cnt_a--;
            }
            else
                arr[row][col] = 1;
        }
        flag++;
    }
    return arr;
}

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout<<"50 50\n";
    vector<vector<ll>> a1=fun(a,b);
    for(ll i=0;i<25;i++)
    {
        for(ll j=0;j<50;j++)
        {
            if(a1[i][j]==0)
            cout<<"A";
            else
            cout<<"B";
        }
        cout<<"\n";
    }
    vector<vector<ll>> a2=fun(c,d);
    for(ll i=0;i<25;i++)
    {
        for(ll j=0;j<50;j++)
        {
            if(a2[i][j]==0)
            cout<<"C";
            else
            cout<<"D";
        }
        cout<<"\n";
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
