#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    ll n;
    cin>>n;
    ll val=n+(n*8)/100;
    if(val<206){
        cout<<"Yay!\n";
    }
    else if(val==206){
        cout<<"so-so\n";
    }
    else{
        cout<<":(\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}