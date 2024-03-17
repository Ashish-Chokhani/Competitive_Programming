#include <bits/stdc++.h>
using namespace std;

long long int N = 200000;
bool sieve[200001];
vector<long long int> primes;
long long int ans = 0;

void CreateSieve()
{
    for (long long int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (long long int i = 2; i<= N; i++)
    {
        if (sieve[i] == true)
        {
            primes.push_back(i);
            for (long long int j = i*i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

vector<long long int> GCD1(200001, 0);

void DFS(long long int cur, long long int par, vector<long long int> *adj, long long int g, vector<long long int> &arr, vector<long long int> &GCD1)
{
    vector<long long int> V;
    for (auto it : adj[cur])
    {
        if (it != par)
        {
            DFS(it, cur, adj, g, arr, GCD1);
            GCD1[cur] = max(GCD1[cur], GCD1[it]);
            V.push_back(GCD1[it]);
        }
        if (arr[cur] % g != 0)
        {
            GCD1[cur] = 0;
        }
        ans = max(ans, GCD1[cur]);
    }
    if (arr[cur] % g == 0)
    {
        GCD1[cur]++;
        ans = max(ans, GCD1[cur]);
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    if (arr[cur] % g == 0 && V.size() >= 2)
    {
        ans = max(ans, GCD1[cur] + V[1]);
    }
}

void solve()
{
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int gc = arr[0];
    for (long long int i = 0; i < n; i++)
    {
        gc = gcd(gc, arr[i]);
    }
    vector<long long int> adj[n];
    for (long long int i = 1; i < n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    CreateSieve();
    // for (long long int i = 0; i < primes.size(); i++)
    // {
    //     vector<long long int> GCD1(200001, 0);
    //     DFS(0, -1, adj, primes[i], arr, GCD1);
    // }
    // if (gc != 1)
    // {
    //     vector<long long int> GCD1(200001, 0);
    //     DFS(0, -1, adj, gc, arr, GCD1);
    // }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}