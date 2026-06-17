#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

class DSU {
    private:
    vector<ll> par, size;
    ll cnt;
    public:
    DSU(int n) {
        par.resize(n);
        size.resize(n, 1);
        cnt = n;
        for(ll i = 0;i < n;i++) par[i] = i;
    }

    ll find(ll node) {
        if(par[node] == node) return node;
        return par[node] = find(par[node]);
    }

    bool unite(ll a, ll b) {
        ll rootA = find(a), rootB = find(b);
        if(rootA == rootB) return false;
        a = rootA, b = rootB;
        if(size[a] < size[b]) {
            swap(a, b);
        }
        par[b] = a;
        size[a] += size[b];
        cnt--;
        return true;
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    ll get_size(ll a) {
        return size[find(a)];
    }

    ll get_cnt() {
        return cnt;
    }
    vector<ll> get_par() {
        return par;
    }
};

void Main() {
    ll n, m;cin >> n >> m;vector<vector<ll>> edges(m);
    for(ll i = 0;i < m;i++) {
        ll a, b, c;cin >> a >> b >> c;a--, b--;
        edges[i] = {c, a, b};
    }
    sort(edges.begin(), edges.end());
    ll total_cost = 0, edges_used = 0;
    DSU dsu(n);
    for(auto x : edges) {
        ll w = x[0], u = x[1], v = x[2];
        if(dsu.unite(u, v)) {
            total_cost += w;
            edges_used++;
        }
    }

    if(edges_used == n - 1) cout << total_cost << "\n";
    else cout << "IMPOSSIBLE" << endl;
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