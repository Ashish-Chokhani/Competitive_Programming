ll kk[10] = {
  89, 
  101, 
  189,
  94,
  621,
  (ll)rng() % 1000 + 1051,
  (ll)rng() % 2000 + 2761,
  (ll)rng() % 4000 + 4441,
  (ll)rng() % 8000 + 8111,
  (ll)rng() % 16000 + 18883
};

ll primes[10] = {
  1000000001020030457,
  735632791,
  776531419,
  797003413,
  1062599999,
  1047899999,
  1031999999, 
  1027799999,
  1018199999,
  1000000007
};

struct string_hash {
  int len;
  ll mod, poly, inv;
  vector<ll> prefix,suffix;
  vector<ll> invs;
  
  void init(int n, string s, ll k = 89, ll m = 1000000007) {
    mod = m;
    poly = k;
    prefix = vector<ll>(n);
    suffix = vector<ll>(n);
    invs = vector<ll>(n);

    invs[0] = 1;
    inv = minv(k);
    for (int i = 1; i < n; i++) {
      invs[i] = (invs[i - 1] * inv) % mod;
    }

    ll x = 1;
    prefix[0] = (s[0] - '0' + 1);
    for (int i = 1; i < n; i++) {
      x = (x * k) % mod;
      prefix[i] = (prefix[i - 1] + x * (s[i] - '0' + 1)) % mod;
    }
    
    x=1;
    suffix[n-1] = (s[n-1] - '0' + 1);
    for (int i = n-2; i >= 0; i--) {
        x = (x * k) % mod;
        suffix[i] = (suffix[i + 1] + x * (s[i] - '0' + 1)) % mod;
    }

    len = n;
  }

  void extend(string next) {
    int x = next.length();
    for (int i = 0; i < x; i++) {
      invs.push_back((invs[i + len - 1] * inv) % mod);
    }

    ll p = mpow(poly, len - 1);
    for (int i = 0; i < x; i++) {
      p = (p * poly) % mod;
      prefix.push_back((prefix[i + len - 1] + p * (next[i] - '0' + 1)) % mod);
    }

    len += x;
  }
  
  void kill(int sz) { // remove last [sz] characters
	  for (int i = 0; i < sz; i++) {
		  invs.pop_back();
		  prefix.pop_back();
	  }
	  
	  len -= sz;
  }

  ll get_hash_prefix(int left, int right) {
    if (left == 0) return prefix[right];
    return ((prefix[right] - prefix[left - 1] + mod) * invs[left]) % mod;
  }
    
  ll get_hash_suffix(int left, int right) {
    if (right == len-1) return suffix[left];
    return ((suffix[left] - suffix[right + 1] + mod) * invs[len-right-1]) % mod;
  }
    
  //To check if a substring is palindrome or not, compare prefix hash with suffix hash

  ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
      if (exp % 2 == 1) {
          res = (res * base) % mod;
      }
      exp >>= 1;
      base = (base * base) % mod;
    }
    return res;
  }
  ll minv(ll base) {
    return mpow(base, mod - 2);
  }
};

template<int K>
struct multihash {
  string_hash sh[K];

  void init(int n, string s) {
    for (int i = 0; i < K; i++) {
      sh[i].init(n, s, kk[9 - i], primes[9 - i]);
    }
  }
  
  void extend(string s) {
	  for (int i = 0; i < K; i++) {
		sh[i].extend(s);
	  }
  }
  
  void kill(int x) {
	  for (int i = 0; i < K; i++) {
		sh[i].kill(x);
	  }
  }

  vector<ll> get_hash(int l, int r) {
    vector<ll> ret(K);
    for (int i = 0; i < K; i++) {
      ret[i] = sh[i].get_hash(l, r);
    }
    return ret;
  }

  bool compare(vector<ll> a, vector<ll> b) {
    for (int i = 0; i < K; i++) {
      if (a[i] != b[i]) return 0;
    }
    return 1;
  }
};
