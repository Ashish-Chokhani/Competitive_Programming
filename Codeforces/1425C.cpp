#include <bits/stdc++.h>
  using namespace std;
  
  typedef long long ll;
  
  ll fun(ll i,ll j,ll extra,vector<pair<ll,char>>&arr,vector<ll>*occ){
    if(i>j) return 0;
    
    ll val=0;
    char cur_char=arr[i].second;
    ll cur_size=arr[i].first+extra;
    
    val=cur_size*cur_size+fun(i+1,j,0,arr,occ);
    for(ll k=0;k<occ[cur_char-'a'].size();k++){
      if(occ[cur_char-'a'][k]<=i || occ[cur_char-'a'][k]>j)
      continue;
      
      val=max(val,fun(i+1,occ[cur_char-'a'][k]-1,0,arr,occ)+fun(occ[cur_char-'a'][k],j,cur_size,arr,occ));
    }
    
    return val;
  }

  int main() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<ll,char>>arr;
    ll i=0,j=0;
    while(i<n && j<n){
      char cur_char=s[i];
      while(j<n && s[j]==cur_char){
        j++;
      }
      ll len=j-i;
      arr.push_back({len,cur_char});
      i=j;
    }
    vector<ll>occ[26];
    ll sz=arr.size();
    for(ll i=0;i<sz;i++){
      occ[arr[i].second-'a'].push_back(i);
    }
    cout<<fun(0,sz-1,0,arr,occ)<<"\n";
    return 0;
  }