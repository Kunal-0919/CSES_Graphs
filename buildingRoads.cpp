#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

void dfs(int node, vector<vector<int>> &g, vector<bool> &vis) {
    vis[node] = true;
    for(auto x : g[node]) {
        if(!vis[x]) dfs(x, g, vis);
    }
}

void Main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0;i < m;i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> par;
    vector<bool> vis(n);
    for(int i = 0;i < n;i++) {
        if(!vis[i]) {
            dfs(i, g, vis);
            par.push_back(i);
        }
    }
    if(par.size() == 1) {
        cout << 0 << endl;
    } else {
        cout << par.size() - 1 << endl;
        for(int i = 1;i < par.size();i++) {
            cout << par[0] + 1 << " " << par[i] + 1 << endl;
        }
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