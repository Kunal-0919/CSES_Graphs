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
vector<vpl> g;

void solve()
{
    cin >> n >> m;
    g.assign(n, vpl());

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
    }

    priority_queue<vl, vvl, greater<vl>> q;
    vvl dist(n, vl(2, LLONG_MAX));
    dist[0][0] = 0;
    dist[0][1] = 0;
    q.push({0, 0, 0});

    while (!q.empty())
    {
        ll d = q.top()[0];
        ll node = q.top()[1];
        ll used = q.top()[2];
        q.pop();
        if (d > dist[node][used])
            continue;
        for (auto x : g[node])
        {
            ll nbr = x.F, edge = x.S;
            if (used)
            {
                // we have already used the discount
                if (dist[nbr][1] > d + edge)
                {
                    dist[nbr][1] = d + edge;
                    q.push({d + edge, nbr, 1});
                }
            }
            else
            {
                if (dist[nbr][0] > d + edge)
                {
                    dist[nbr][0] = d + edge;
                    q.push({d + edge, nbr, 0});
                }
                if (dist[nbr][1] > d + edge / 2)
                {
                    dist[nbr][1] = d + edge / 2;
                    q.push({d + edge / 2, nbr, 1});
                }
            }
        }
    }
    cout << min(dist[n - 1][1], dist[n - 1][0]) << endl;
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