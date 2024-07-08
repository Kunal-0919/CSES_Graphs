#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define SQ(a) (a) * (a)
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define endl '\n'
#define F first
#define S second
static const auto DPSolver = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef set<ll> si;
typedef set<ll> sl;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef priority_queue<ll> minHeap;
typedef priority_queue<ll, vl, greater<ll>> maxHeap;
typedef map<ll, ll> mii;
typedef map<string, ll> msi;

const ld pi = 3.14159265358979323846;
ll mod = 1e9 + 7;
ll n, m;
vector<vector<ll>> g;
int vis[100001];

void dfs(ll n)
{
    vis[n] = 1;
    for (auto x : g[n])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
}

void solve()
{
    cin >> n >> m;
    g.assign(n + 1, vector<ll>());
    memset(vis, 0, sizeof(vis));
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vl nodes;
    for (ll i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            nodes.push_back(i);
        }
    }
    cout << nodes.size() - 1 << endl;

    for (ll i = 1; i < nodes.size(); i++)
    {
        cout << nodes[i - 1] << " " << nodes[i] << endl;
    }
}

int main()
{

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
