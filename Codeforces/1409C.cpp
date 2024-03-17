#include <bits/stdc++.h>
using namespace std;

bool isPossible(int diff, int x, int y, int k)
{
    if (((y - x) % diff) != 0)
        return false;
    int acc = (y - x) / diff;
    acc--;
    if (acc > k)
        return false;
    if (acc <= k)
        return true;
    return false;
}

void solve()
{
    int n, x, y, i;
    cin >> n >> x >> y;
    cout << x << " " << y << " ";
    n -= 2;
    for (i = 1; i <= (y - x); i++)
    {
        if (isPossible(i, x, y, n))
        {
            for (int j = x + i; j < y; j += i)
            {
                cout << j << " ";
                n--;
            }
            break;
        }
    }
    int control = x - i;
    while (n > 0 && control >= 1)
    {
        cout << control << " ";
        n--;
        control -= i;
    }
    control = y + i;
    while (n > 0)
    {
        cout << control << " ";
        n--;
        control+=i;
    }
    cout<<"\n";
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