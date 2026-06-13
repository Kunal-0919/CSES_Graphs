#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:247474112")
#endif

void Main() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        g[a].push_back({b, c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (d != dist[u]) continue; // stale
        for (auto [v, wt] : g[u]) {
            if (dist[v] > d + wt) {
                dist[v] = d + wt;
                q.push({dist[v], v});
            }
        }
    }
    for (auto x : dist) cout << x << " "; 
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        Main();
    }
    return 0;
}