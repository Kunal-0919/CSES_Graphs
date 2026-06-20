#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

void dfs(ll node, vector<vector<ll>>&g, vector<bool>&vis) {
    vis[node] = true;
    for(auto x: g[node]) {
        if(!vis[x]) dfs(x, g, vis);
    }
    // order.push_back(node);
}


void Main() {
    ll n, m;cin >> n >> m; vector<vector<ll>> g(n), G(n);
    for(ll i = 0;i < m;i++) {
        ll a, b;cin >> a >> b;a--, b--;
        g[a].push_back(b); G[b].push_back(a);
    }
    vector<bool> vis(n);
    dfs(0, g, vis);
    for(ll i = 0;i < n;i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i + 1 << endl;return;
        }
    }
    vis.assign(n, false);
    dfs(0, G, vis);
    for(ll i = 0;i < n;i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            cout << i + 1 << " " << 1 << endl;return;
        }
    }
    cout << "YES" << endl;
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