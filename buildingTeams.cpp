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

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll>());

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // we need to check bipartiteness of this tree
    vector<char> color(n, ' '); // do we need visited array => NO
    queue<pair<ll, ll>> q;      // queue to store the node and the color assigned to it (we can use only the node)
    for (ll i = 0; i < n; i++)
    {
        if (color[i] == ' ')
        {
            q.push({i, 'R'});
            color[i] = 'R';

            while (!q.empty())
            {
                pair<ll, ll> curr = q.front();
                q.pop();
                for (auto x : g[curr.first])
                {
                    if (color[x] == ' ')
                    {
                        color[x] = (curr.second == 'R') ? 'B' : 'R'; // assigning the opposite color
                        q.push({x, color[x]});
                    }
                    else if (color[x] == curr.second)
                    {
                        cout << "IMPOSSIBLE" << endl;
                        return;
                    }
                }
            }
        }
    }
    for (auto x : color)
    {
        if (x == 'R')
            cout << 1 << " ";
        else
            cout << 2 << " ";
    }
    cout << endl;
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