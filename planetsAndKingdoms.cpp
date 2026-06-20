#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
// typdef vector<int> vi;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

void dfs1(ll node, vector<vector<ll>>&g, vector<bool>&vis, vector<ll> &order) {
    vis[node] = true;
    for(auto v : g[node]) {
        if(!vis[v]) dfs1(v, g, vis, order);
    }
    order.push_back(node);
}

void dfs2(ll node, vector<vl>&g, vl &comp, ll cid) {
    comp[node] = cid;
    for(auto x : g[node]) {
        if(comp[x] == -1) dfs2(x, g, comp, cid);
    }
}

void Main() {
    ll n, m;cin >> n >> m;
    vector<vector<ll>> g(n), G(n);
    for(ll i = 0;i < m;i++) {
        ll a, b;cin >> a >> b;a--, b--;
        g[a].push_back(b); G[b].push_back(a);
    }
    vector<bool>vis(n, false);
    vector<ll>order;
    for(ll i = 0;i < n;i++) {
        if(!vis[i]) {
            dfs1(i, g, vis, order);
        }
    }
    vl comp(n, -1);
    reverse(order.begin(), order.end());
    ll cid = 1;
    for(auto x : order) {
        if(comp[x] == -1) {
            dfs2(x, G, comp, cid); cid++;
        }
    }

    cout << cid - 1 << endl;
    for(auto x: comp) cout << x << " ";
    cout << endl;

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