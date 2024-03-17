#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const ll mod = 1000000007; //998244353
const ll INF = 1e18;
template<class T>void print(T x)
{
  cerr << x;
}
template<class T, class V>
         void print(pair<T , V> x)
{
  print(x.first); 
  cerr << ':';
  print(x.second);
}
template<class T>
         void print(vector<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(set<T,
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(multiset<T, 
                    greater<T>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T>
         void print(unordered_set<T> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x);
    cerr << ' ';
  }
  cerr << ']';
}
template<class T, class V>
         void print(vector<pair<T, V>> &a)
{
  cerr << '[' << ' ';
  for(auto x : a)
  {
    print(x.first);
    cerr << ":"; 
    print(x.second);
    cerr << ' ';
  }
  cerr << ']';
}
template <class T, class V> 
          void print(map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T, class V> 
          void print(unordered_map <T, V> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template <class T> 
          void print(vector<vector<T>> &a) 
{
  cerr << "[ "; 
  for (auto i : a) 
  {
    print(i); 
    cerr << " ";
  } 
  cerr << "]";
}
template<class T>
         void print(stack<T> &a)
{
  cerr << '[' << ' ';
  stack<T>temp=a;
  while(!temp.empty())
  {
    auto val=temp.top();
    temp.pop();
    print(val); 
    cerr << " ";
  }
  cerr << ']';
}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "  "; print(x); cerr << '\n';
#else
#define debug(x)
#endif

using i64 = long long;

std::vector<int> kmp(std::string s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }
    
    sort(S.begin(), S.end(),
        [&](string a,string b) {
            return a.size() < b.size();
        });
    std::vector<std::string> tmp;
    for (int i = 0; i < N; i++) {
        bool ok = true;
        for (int j = i + 1; j < N; j++) {
            auto f = kmp(S[i] + '#' + S[j]);
            if (std::find(f.begin(), f.end(), S[i].size()) != f.end()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            tmp.push_back(S[i]);
        }
    }
    S = tmp;
    N = S.size();
    
    debug(S);
        
    vector<vector<int>>cost(N,vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            auto f = kmp(S[j] + '#' + S[i]);
            cost[i][j] = S[j].size() - f.back();
        }
    }
    vector<vector<int>>dp(1 << N,vector<int>(N, 1E9));
    for (int i = 0; i < N; i++) {
        dp[1 << i][i] = S[i].size();
    }
    for (int s = 1; s < (1 << N); s++) {
        for (int i = 0; i < N; i++) {
            if (s >> i & 1) {
                for (int j = 0; j < N; j++) {
                    if (~s >> j & 1) {
                        dp[s | 1 << j][j] = std::min(dp[s | 1 << j][j], dp[s][i] + cost[i][j]);
                    }
                }
            }
        }
    }
    
    int ans = *std::min_element(dp.back().begin(), dp.back().end());
    std::cout << ans << "\n";
    
    return 0;
}