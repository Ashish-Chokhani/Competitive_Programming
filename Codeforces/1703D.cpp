#include <bits/stdc++.h>
using namespace std;
 
typedef struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
} Node;
 
class Trie
{
private:
    Node *root;
 
public:
    Trie()
    {
        root = new Node();
    }
 
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
 
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
 
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
 
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;
 
            node = node->get(prefix[i]);
        }
        return true;
    }
};
 
void solve()
{
    Trie T;
    int n;
    cin >> n;
    vector<int> ans(n, 0);
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        T.insert(s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int l = s[i].length();
        if (ans[i] == 0)
        {
            for (int j = 1; j < l; j++)
            {
                string s1 = s[i].substr(0, j);
                string s2 = s[i].substr(j, l - j);
                if (T.search(s1) && T.search(s2))
                {
                    ans[i] = 1;
                    break;
                }
            }
        }
    }
    for (auto it : ans)
        cout << it;
    cout << "\n";
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