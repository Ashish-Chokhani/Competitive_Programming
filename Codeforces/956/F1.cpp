#include "bits/stdc++.h"
#ifdef mlocal
#include "./Competitive-Code-Library/snippets/prettyprint.h"
#endif
using namespace std;
#define for_(i, s, e) for (int i = s; i < (int) e; i++)
#define for__(i, s, e) for (ll i = s; i < e; i++)
typedef long long ll;
typedef vector<int> vi;
typedef array<int, 2> ii;
#define endl '\n'

const int INF = 1e9;
const int MXB = 31;

class Trie {
public:
    int node = 1;

    void reset() {
        for_(i, 0, node + 2) opt[node] = INF;
        for_(i, 0, node + 2) child[i][0] = child[i][1] = 0;
        node = 1;
    }

    void insert(int s, int idx) {
        int p = 0;
        for (int b = MXB - 1; b >= 0; b--)  {
            int i = (s >> b) & 1;
            if (!child[p][i]) {
                opt[node] = INF;
                child[p][i] = node++;
            }
            p = child[p][i];
            opt[p] = min(opt[p], idx);
        }
    }

    void rem(int s) {
        int p = 0;
        for (int b = MXB - 1; b >= 0; b--)  {
            int i = (s >> b) & 1;
            int new_p = child[p][i];
            if (!new_p) break;
            child[p][i] = 0;
            p = new_p;
            opt[p] = INF;
        }
    }

    int find_close(int src, int target) {
        int ans = INF, p = 0;
        for (int b = MXB - 1; b >= 0; b--) {
            int tb = (target >> b) & 1, sb = (src >> b) & 1;
            int towards = tb ^ sb;
            if (tb and child[p][1 - towards]) ans = min(ans, opt[child[p][1 - towards]]);

            if (!child[p][towards]) break;
            p = child[p][towards];
        }

        return ans;
    }

private:
    static constexpr int MXN = 2e6, MXV = 2; // max node count (worst case: max sequence length * count), max sequence value
    int child[MXN][MXV], opt[MXN + 1];
} trie;

void solve() {
    int n; ll k; cin >> n >> k;
    vi a(n);
    for_(i, 0, n) cin >> a[i];

    unsigned int l = 0, r = 16, ans = r;
    while (l < r) {
        unsigned int mid = (l + r) / 2;

        ll ct = 0;
        int sm_from = n;
        for (int i = n - 1; i >= 0; i--) {
            sm_from = min(sm_from, trie.find_close(a[i], mid));
            trie.insert(a[i], i);
            ct += n - sm_from;
        }

        trie.reset();
        if (ct <= k - 1) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << ans << endl;
}

int main() {
#ifdef mlocal
    freopen("test.in", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

