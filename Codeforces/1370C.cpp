#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool checkPrime(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        if ((n / i) != i)
            cnt++;
        }
    }
    return cnt == 2;
}

void solve()
{
    ll n;
    cin >> n;
    bool isPrime=false;
    if(n%2==0)
    {
        isPrime=checkPrime(n/2);
    }
    bool isEven=true;
    ll temp=n;
    while(temp>1)
    {
        if(temp%2!=0)
        {
        isEven=false;
        break;
        }
        temp=temp/2;
    }
    isEven&=n>2;
    if(n==1 || isPrime || isEven)
    {
        cout<<"FastestFinger\n";
    }
    else
        cout<<"Ashishgup\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}