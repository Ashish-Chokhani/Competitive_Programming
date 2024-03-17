#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s1;
    cin>>s1;
    vector<int>code(n);
    for(int i=0;i<n;i++)
    {
        code[i]=(int)s1[i]-48;
    }
    vector<char>ans;
    for(int i=n-1;i>=0;i--)
    {
        if(code[i]!=0)
        ans.push_back((char)(code[i]+96));
        else
        {
            int no=(code[i-2]*10)+code[i-1];
            ans.push_back((char)(no+96));
            i-=2;
        }
    }
    reverse(ans.begin(),ans.end());
    string s(ans.begin(),ans.end());
    cout<<s<<"\n";
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        solve();
    }
    return 0;
}