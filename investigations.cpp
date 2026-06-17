#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

void Main() {
    ll n, m;cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n);
    for(ll i = 0;i < m;i++) {
        ll a, b,c;cin >> a >> b >> c;a--, b--;
        g[a].push_back({b, c});
    }
    vector<ll> dist(n, LLONG_MAX); dist[0] = 0;
    vector<ll> ways(n, 0); ways[0] = 1;
    vector<ll> miniFlights(n, LLONG_MAX);
    vector<ll> maxiFlights(n, LLONG_MIN);
    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});
    miniFlights[0] = 0;
    maxiFlights[0] = 0;

    while(!q.empty()) {
        pair<ll, ll> top = q.top();q.pop();
        ll d = top.first, curr = top.second;
        if(d != dist[curr]) continue;
        for(auto [v, w] : g[curr]) {
            ll newDist = dist[curr] + w;
            if(newDist < dist[v]) {
                dist[v] = newDist;
                ways[v] = ways[curr];
                miniFlights[v] = 1 + miniFlights[curr];
                maxiFlights[v] = 1 + maxiFlights[curr];
                q.push({newDist, v});
            } else if(newDist == dist[v]) {
                ways[v] = (ways[v] + ways[curr]) % MOD;
                miniFlights[v] = min(miniFlights[curr] + 1, miniFlights[v]);
                maxiFlights[v] = max(maxiFlights[curr] + 1, maxiFlights[v]);

            }
        }
    }

    cout << dist[n  - 1] << " " << ways[n - 1] << " " << miniFlights[n - 1] << " " << maxiFlights[n - 1] << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--) {
        Main();
    }
    return 0;
}