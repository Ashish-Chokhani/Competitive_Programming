#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n;
    cin>>n;
    ll i=1;
    while(1)
    {
        ll val=(i*(i+1))/2;
        if(val>=n){
            cout<<i<<"\n";
            break;
        }
        i++;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}