#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

ll findSum(ll n){
    ll s=0;
    while(n>0){
        s+=n%10;
        n/=10;
    }
    return s;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    while(1){
        ll val=findSum(n);
        if(val%k==0){
            cout<<n<<"\n";
            break;
        }
        n++;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    solve();
}