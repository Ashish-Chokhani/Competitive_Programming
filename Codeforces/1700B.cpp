#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(long long int no, long long int digits)
{
    long long int x = no, y = 0;
    while (x > 0)
    {
        long long int r = x % 10;
        y = (y * 10) + r;
        x = x / 10;
    }
    return y == no;
}

long long int countDigits(long long int n)
{
    long long int c = 0;
    while (n > 0)
    {
        c++;
        n = n / 10;
    }
    return c;
}

void solve()
{
    long long int n, x;
    cin >> n;
    cin >> x;
    long long int i = x;
    while (1)
    {
        if (isPalindrome(i, n + 1) && countDigits(i-x) == n)
        {
            cout << (i - x) << "\n";
            break;
        }
        i++;
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
}