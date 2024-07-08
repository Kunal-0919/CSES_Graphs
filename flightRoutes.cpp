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
}

const lld pi = 3.14159265358979323846;
ll mod = 1e9 + 7;

ll n, m, k;
vector<vpl> g;

void solve()
{
    cin >> n >> m >> k;
    g.assign(n, vpl());
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back({b, c});
    }
    priority_queue<vl, vvl, greater<vl>> q;
    q.push({0, 0});
    vector<priority_queue<ll>> maxH(n);
    maxH[0].push(0);
    while (!q.empty())
    {
        ll d = q.top()[0], node = q.top()[1];
        q.pop();
        if (maxH[node].size() > 0 && maxH[node].top() < d)
            continue;
        for (auto x : g[node])
        {
            if (maxH[x.F].size() < k || x.S + d < maxH[x.F].top())
            {
                if (maxH[x.F].size() == k)
                    maxH[x.F].pop();
                maxH[x.F].push(x.S + d);
                q.push({x.S + d, x.F});
            }
        }
    }

    vl res;
    while (!maxH[n - 1].empty())
    {
        res.PB(maxH[n - 1].top());
        maxH[n - 1].pop();
    }

    reverse(range(res));
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}

int main()
{
    setIO();
    ll t = 1;
    // t--;
    while (t--)
    {
        solve();
    }
}