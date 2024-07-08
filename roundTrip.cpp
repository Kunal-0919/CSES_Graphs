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
vl vis, last, par;
vl ans;

void dfs(ll n, ll p)
{
    vis[n] = 1;
    par[n] = p;
    last[n] = 1;

    for (auto x : g[n])
    {
        if (x == p)
            continue;
        if (!vis[x])
        {
            dfs(x, n);
        }
        else
        {
            if (last[x] == 1)
            {
                if (ans.empty())
                {
                    ll node = n;

                    ans.PB(x);
                    while (node != x)
                    {
                        ans.PB(node);
                        node = par[node];
                    }
                    ans.PB(x);
                }
            }
        }
    }
    last[n] = 0;
}
void solve()
{
    cin >> n >> m;
    g.assign(n, {});
    vis.assign(n, 0);
    last.assign(n, -1);
    par.assign(n, -2);

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, -1);
    }
    if (ans.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << ans.size() << endl;
    reverse(range(ans));
    for (auto x : ans)
    {
        cout << x + 1 << " ";
    }

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