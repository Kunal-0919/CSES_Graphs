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
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
    q.push({0, 0, 0});
    vector<vector<ll>> dist(n, vector<ll>(2, LLONG_MAX));
    dist[0][0] = 0, dist[0][1] = 0;
    
    while(!q.empty()) {
        vector<ll> top = q.top();q.pop();
        ll d = top[0], used = top[1], curr = top[2];
        if(d > dist[curr][used]) continue; // stale values inside the heap
        for(auto [v, w] : g[curr]) {
            if(used) {
                if(dist[v][used] > w + d) {
                    dist[v][used] = w + d;
                    q.push({w + d, used, v});
                }
            } else {
                if(dist[v][used] > d + w) {
                    dist[v][used] = d + w;
                    q.push({d + w, used, v});
                }
                if(dist[v][used + 1] > d + w / 2) {
                    dist[v][used + 1] = d + (w / 2);
                    q.push({d + w / 2, used + 1, v});
                }
            }
        }
    }

    cout << min(dist[n - 1][0], dist[n - 1][1]) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    while (t--) {
        Main();
    }
    return 0;
}