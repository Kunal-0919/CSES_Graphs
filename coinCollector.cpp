#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

void dfs1(ll node, vector<vl>&g, vb &vis, vl &order) {
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
    ll n, m;cin >> n >> m;vector<vl> g(n), G(n);vl v(n); vector<vl> edges(m);
    for(ll &x : v) cin >> x;
    for(ll i = 0;i < m;i++) {
        ll a, b;cin >> a >> b;a--, b--;
        edges[i] = {a, b};
        g[a].push_back(b); G[b].push_back(a);
    }
    vb vis(n, false); vl order;
    for(ll i = 0;i < n;i++) {
        if(!vis[i]) dfs1(i, g, vis, order);
    }
    reverse(order.begin(), order.end());
    ll cid = 0;
    vl comp(n, -1);
    for(auto i : order) {
        if(comp[i] == -1) dfs2(i, G, comp, cid++);
    }
    vector<vl> graph(cid);
    vl in(cid);
    for(auto x : edges) {
        ll a = x[0], b = x[1];
        ll kingdom_a = comp[a], kingdom_b = comp[b];
        if(kingdom_a == kingdom_b) continue;
        graph[kingdom_a].push_back(kingdom_b);
        in[kingdom_b]++;
    }
    vl weights(cid);
    for(ll i = 0;i < n;i++) {
        weights[comp[i]] += v[i];
    }

    // now we do topo sort
    queue<ll> q;vl topo;
    vl dp(cid, LLONG_MIN);
    for(ll i = 0;i < cid;i++) {
        dp[i] = weights[i];
        if(in[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        ll curr = q.front();q.pop();
        topo.push_back(curr);
        for(auto x : graph[curr]) {
            in[x]--;
            if(in[x]) continue;
            q.push(x);
        }
    }
    
    for(auto x : topo) {
        for(auto v : graph[x]) {
            dp[v] = max(dp[v], dp[x] + weights[v]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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