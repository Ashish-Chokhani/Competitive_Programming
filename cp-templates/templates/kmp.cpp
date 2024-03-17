vector<int> compute_lps(vector<ll> pat) {
    int n = pat.size();
    vector<int> lps(n);
    lps[0] = 0;
    for (int i = 1; i < n; i++) {
        lps[i] = 0;
        int j = lps[i - 1]; /* trying length j + 1 */
        while (j > 0 && pat[j] != pat[i]) {
            j = lps[j - 1];
        }
        if (pat[j] == pat[i]) {
            lps[i] = j + 1;
        }
    }
    return lps;
}
