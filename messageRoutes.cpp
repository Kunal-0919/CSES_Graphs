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

void solve()
{
    cin >> n >> m;
    g.assign(n, {});

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<ll> q;
    vl dist(n, LLONG_MAX);
    q.push(0);
    dist[0] = 0;
    vl par(n, -1);
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        for (auto x : g[node])
        {
            if (dist[x] == LLONG_MAX)
            {
                dist[x] = 1 + dist[node];
                q.push(x);
                par[x] = node;
            }
        }
    }
    if (dist[n - 1] == LLONG_MAX)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << dist[n - 1] + 1 << endl;
    vl ans;
    ll x = n - 1;
    while (x != -1)
    {
        ans.PB(x);
        x = par[x];
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