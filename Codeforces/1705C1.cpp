#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n,c,q;
    cin>>n>>c>>q;
    string s;
    cin>>s;
    string s1=" ";
    s1+=s;
    for(int i=1;i<=c;i++)
    {
        int l,r;
        cin>>l>>r;
        s1+=s1.substr(l,r-l+1);
    }
    for(int i=1;i<=q;i++)
    {
        int k;
        cin>>k;
        cout<<s1[k]<<"\n";
    }
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}