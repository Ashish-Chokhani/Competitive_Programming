#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    vector<string>s(10);
    ll points=0;
    for(ll i=0;i<10;i++){
        cin>>s[i];
    }
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            if(s[i][j]=='X'){
                ll newX=i;
                ll newY=j;
                if(newX>=5) newX=9-i;
                if(newY>=5) newY=9-j;
                if(newX==0 || newY==0){
                    points+=1;
                }
                else if(newX==1 || newY==1){
                    points+=2;
                }
                else if(newX==2 || newY==2){
                    points+=3;
                }
                else if(newX==3 || newY==3){
                    points+=4;
                }
                else if(newX==4 || newY==4){
                    points+=5;
                }
            }
        }
    }
    cout<<points<<"\n";
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
    return 0;
}