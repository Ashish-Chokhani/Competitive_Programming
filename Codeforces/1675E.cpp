#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    char maxiChar='a',miniReducibleTo='z',tempReducibleTo='z',tempChar='a';
    ll i=0;
    while(i<n){
        if(s[i]=='a'){
            i++;
            continue;
        }
        else{
            if(s[i]<=maxiChar){
                s[i]=miniReducibleTo;
            }
            else{
                ll req=s[i]-maxiChar;
                if(k>=req){
                    maxiChar=max(maxiChar,s[i]);
                    s[i]='a';
                    k-=req;
                    miniReducibleTo='a';
                }
                else{
                    s[i]=s[i]-k;
                    if(tempChar=='a'){
                        tempChar=s[i]+k;
                        tempReducibleTo=s[i];
                    }
                    k=0;
                }
            }
        }
        i++;
    }
    for(ll i=0;i<n;i++) if(s[i]<=tempChar) s[i]=min(s[i],tempReducibleTo);
    cout<<s<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}