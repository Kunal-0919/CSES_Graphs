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

// ******************************** DSU ********************************
class DSU
{
public:
    vl size, par;
    ll maxsz = 1;
    DSU(ll n)
    {
        size.assign(n, 1);
        par.resize(n);
        for (ll i = 0; i < n; i++)
            par[i] = i;
    }

    ll find(ll n)
    {
        if (n == par[n])
            return n;
        return par[n] = find(par[n]);
    }

    void uniion(ll a, ll b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return;
        if (size[a] >= size[b])
        {
            size[a] += size[b];
            par[b] = a;
        }
        else
        {
            size[b] += size[a];
            par[a] = b;
        }
        maxsz = max(maxsz, max(size[a], size[b]));
    }
};

// ******************************** DSU ********************************

void solve()
{
    ll n, m;
    cin >> n >> m;
    DSU ds(n);
    ll cnt = n;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if (ds.find(a) != ds.find(b))
        {
            cnt--;
            ds.uniion(a, b);
        }
        cout << cnt << " " << ds.maxsz << endl;
    }
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