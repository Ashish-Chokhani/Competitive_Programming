#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void solve()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<ll>freq(26,0);
    for(ll i=0;i<n;i++){
        freq[s[i]-97]++;
    }
    for(ll i=0;i<26 && k>0;i++){
        if(freq[i]&1){
            k--;
            freq[i]--;
        }
    }
    if(k & 1){
        for(ll i=0;i<26;i++){
            if(freq[i]>0){
                k--;
                freq[i]--;
                break;
            }
        }
    }
    ll isAns=0;
    for(ll i=0;i<26;i++){
        if(freq[i] & 1){
            isAns++;
        }
    }
    cout<< (isAns<=1 ? "YES\n" : "NO\n");
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