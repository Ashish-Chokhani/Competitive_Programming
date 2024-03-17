#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    stack<ll>ind;
    stack<pair<char,ll>>st;
    for(ll i=0;i<n;i++){
        if(s[i]=='('){
            ind.push(i);
            st.push({s[i],i});
        }
        else{
            if(s[i]!=')') st.push({s[i],i});
            else{
                if(ind.empty()) st.push({s[i],i});
                else{
                    ll prev=ind.top();
                    ind.pop();
                    while(!st.empty() && st.top().second!=prev) st.pop();
                    if(!st.empty()) st.pop();
                }
            }
        }
    }
    vector<char>ans;
    while(!st.empty()){
        char ch=st.top().first;
        st.pop();
        ans.push_back(ch);
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it;
    cout<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}