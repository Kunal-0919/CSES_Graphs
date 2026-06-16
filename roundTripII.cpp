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
 
vector<ll> ans;
 
void dfs(ll node, ll p, vector<vector<ll>>&g, vector<bool>&vis, vector<ll>&par, vector<bool>& state) {
    if(!ans.empty()) return;
    state[node] = true, vis[node] = true, par[node] = p;
    for(auto x : g[node]) {
        if(!vis[x]) dfs(x, node, g, vis, par, state);
        else if(state[x]) {
            if(ans.empty()) {
                ll curr = node;
                ans.push_back(x);
                while(curr != x) {
                    ans.push_back(curr);curr = par[curr];
                }
                ans.push_back(x);
            }
        }
    }
    state[node] = false;
}
 
void Main() {
    ll n, m;cin >> n >> m;
    vector<vector<ll>> g(n);
    for(ll i = 0;i < m;i++) {
        ll a, b;cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    vector<bool> vis(n, false), state(n, false); vector<ll> par(n, -2);
    for(ll i = 0;i < n;i++) {
        if(!vis[i]) {
            dfs(i, -1, g, vis, par, state);
        }
        if(!ans.empty()) break;
    }
 
    if(ans.empty()) cout << "IMPOSSIBLE" << endl;
    else {
        cout << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        for(auto x : ans) cout << x + 1 << " ";cout << endl;
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