#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MP make_pair
#define rep(i, a, n) for (ll i = a; i <= n; i++)
#define sq(a) (a) * (a)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl '\n'
#define f first
#define s second
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<ll>> vvl;
typedef vector<vector<bool>> vvb;
typedef set<ll> si;
typedef set<ll> sl;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef priority_queue<ll> maxHeap;
typedef priority_queue<ll, vl, greater<ll>> minHeap;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    // if (sz(name))
    // {
    // freopen((name + ".in").c_str(), "r", stdin);
    // freopen((name + ".out").c_str(), "w", stdout);
    // }
}

const lld pi = 3.14159265358979323846;
ll mod = 1e9 + 7;

ll n, m;
vector<vl> g;
vb vis;
void dfs(ll n)
{
    vis[n] = 1;
    for (auto x : g[n])
    {
        if (!vis[x])
            dfs(x);
    }
}
void solve()
{
    cin >> n >> m;
    g.assign(n, {});
    vis.assign(n, 0);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        // g[b].push_back(a);
    }
    dfs(0);
    if (!vis[n - 1])
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
            g[i].clear();
    }
    vl in(n);
    for (ll i = 0; i < n; i++)
    {
        for (auto x : g[i])
            in[x]++;
    }
    queue<ll> q;
    q.push(0);
    vl dist(n, LLONG_MAX);
    dist[0] = 1;
    vl par(n, -1);

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (auto x : g[node])
        {
            in[x]--;
            if (!in[x])
            {
                dist[x] = 1 + dist[node];
                q.push(x);
                par[x] = node;
            }
        }
    }
    cout << dist[n - 1] << endl;

    ll node = n - 1;
    vl ans;
    while (node != -1)
    {
        ans.pb(node);
        node = par[node];
    }
    reverse(range(ans));
    for (auto x : ans)
        cout << x + 1 << " ";
    cout << endl;
}

int main()
{
    setIO();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}