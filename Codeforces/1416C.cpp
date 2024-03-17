#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

struct Node{
    Node*links[26];
    ll val;

    bool containsKey(char ch){
        return links[ch-'a'];
    }

    ll findVal(){
        return val;
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    void putVal(char ch,ll value){
        links[ch-'a']->val+=value;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

};

class Trie{
    private: Node*root;

    public:
    Trie(){
        root=new Node();
    }

    void insert(string word,ll val){
        Node *node = root;
        for(ll i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node->putVal(word[i],val);
            node=node->get(word[i]);
        }
    }

    ll findValue(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            node=node->get(word[i]);
        }
        return node->findVal();
    }
};

void solve()
{
    Trie tr;
    ll n;
    cin>>n;
    map<string,int>mp;
    while(n--){
        char ch;
        cin>>ch;
        if(ch=='I'){
            string word;
            ll freq;
            cin>>word>>freq;
            tr.insert(word,freq);
            mp[word]=freq;
        }
        else if(ch=='Q'){
            //cout<<"Ok\n";
            string word;
            cin>>word;
            cout<<tr.findValue(word)<<"\n";
        }
        else{
            string word;
            ll freq;
            cin>>word>>freq;
            ll diff=freq-mp[word];
            mp[word]=freq;
            tr.insert(word,diff);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}