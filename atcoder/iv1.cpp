#include <bits/stdc++.h>
using namespace std;

void Solution()
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string start = "bbaa", end = "babb";
    vector<string> dict;
    dict.push_back("baba");
    dict.push_back("abba");
    dict.push_back("aaba");
    dict.push_back("bbbb");
    dict.push_back("abaa");
    dict.push_back("abab");
    dict.push_back("aaab");
    dict.push_back("abba");
    dict.push_back("bbba");
    dict.push_back("aaab");
    dict.push_back("abaa");
    dict.push_back("baba");
    dict.push_back("baaa");
    vector<vector<string>> ans;
    unordered_set<string> st(dict.begin(), dict.end());
    st.insert(start);
    st.insert(end);
    queue<vector<string>> q;
    q.push({start});
    st.erase(start);
    vector<string> newWords;
    int level = 0;

    while (!q.empty())
    {
        vector<string> words = q.front();
        q.pop();
        string word = words.back();
        if (words.size() > level)
        {
            level++;

            for (auto it : newWords)
            {
                st.erase(it);
            }
        }
        if (word == end){
            if(ans.size()==0) ans.push_back(words);
            else if(ans[0].size()==words.size()) ans.push_back(words);
        }
        for (int i = 0; i < word.length(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    if (word == "bbba")
                        cout << level << "\n";
                    words.push_back(word);
                    q.push(words);
                    words.pop_back();
                    newWords.push_back(word);
                }
            }
            word[i] = original;
        }
    }
    for (auto it : ans)
    {
        for (auto x : it)
            cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    Solution();
    return 0;
}