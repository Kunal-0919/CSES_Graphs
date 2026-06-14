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
    ll n, m;cin >> n >> m;
    vector<vector<ll>> edges(m);
    vector<ll> dist(n,0);vector<ll> par(n, -1);
    for(ll i = 0;i < m;i++) {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        edges[i] = {a, b, c};
    }
    dist[0] = 0; ll last = -1;
    for(ll i = 0;i < n;i++) {
        last = -1;
        for(auto edge : edges) {
            ll u = edge[0], v = edge[1], w = edge[2];
            if(dist[u] != LLONG_MAX && dist[v] > w + dist[u]) {
                dist[v] = dist[u] + w;
                last = v;
                par[v] = u;
            }
        }
    }
    if(last == -1) {
        cout << "NO" << endl;return;
    }
    for(ll i = 0;i < n;i++) last = par[last];
    vector<ll> ans; ll node = last;
    do {
        ans.push_back(node);
        node = par[node];
    } while(last != node);
    ans.push_back(node);
    cout << "YES" << endl;
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x + 1 << " ";cout << endl;
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