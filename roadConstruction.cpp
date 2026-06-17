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
    ll cnt, maxi;
    public:
    DSU(int n) {
        par.resize(n);
        size.resize(n, 1);
        cnt = n;
        maxi = 1;
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
        maxi = max(maxi, size[a]);
        cnt--;
        return true;
    }
    bool same(ll a, ll b) { return find(a) == find(b); }
    ll get_size(ll a) { return size[find(a)]; }
    ll get_cnt() { return cnt; }
    vector<ll> get_par() { return par; }
    ll max_sz_component() { return maxi; }
};

void Main() {
    ll n, m;cin >> n >> m; DSU dsu(n);
    for(ll i = 0;i < m;i++) {
        ll a, b;cin >> a >> b;a--, b--;
        dsu.unite(a, b);
        cout << dsu.get_cnt() << " " << dsu.max_sz_component() << endl;
    }
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