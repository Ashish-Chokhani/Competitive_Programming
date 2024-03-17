#include <bits/stdc++.h>
using namespace std;

bool isOpposingPresent(vector<int>&isPresent,string&s){
    return isPresent[s[0]-'A']>=1 && isPresent[s[1]-'A']>=1;
}

bool isCombiningPresent(string &s,string &combining){
    string compareString = "";
    compareString+=combining[0];
    compareString+=combining[1];
    string reversed_string=combining;
    reverse(reversed_string.begin(),reversed_string.end());
    return (s==compareString) || (reversed_string==s);
}

void solve()
{
    int n;
    cin>>n;
    string combining,s;
    vector<string>opposing(n);
    map<string,int>mp;
    cin>>combining>>s;
    vector<int>isPresent(26,0);
    for(int i=0;i<n;i++){
        cin>>opposing[i];
        mp[opposing[i]]=1;
    }
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
            isPresent[s[i]-'A']++;
            continue;
        }
        char prevElement=st.top();
        string newString = "";
        newString +=prevElement;
        newString += s[i];
        if(isCombiningPresent(newString,combining)){
            char topele=st.top();
            st.pop();
            isPresent[topele-'A']--;
            st.push(combining[2]);
            isPresent[combining[2]-'A']++;
            continue;
        }
        int flag=1;
        for(char ch='A';ch<='Z' && flag==1;ch++){
            string temp="";
            temp+=ch;
            temp+=s[i];
            if(isOpposingPresent(isPresent,temp)){
                while(!st.empty()){
                    char ele=st.top();
                    cout<<"Popping "<<ele<<"\n";
                    st.pop();
                    isPresent[ele-'A']--;
                }
                flag=0;
            }
        }
        if(flag){
            st.push(s[i]);
            isPresent[s[i]-'A']++;
        }
    }
    vector<char>arr;
    while(!st.empty()){
        arr.push_back(st.top());
        st.pop();
    }
    reverse(arr.begin(),arr.end());
    for(auto it: arr){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
