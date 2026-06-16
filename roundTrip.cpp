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

vector<int> ans;

void dfs(int node, int p, vector<vector<int>> &g, vector<bool>&vis, vector<int>&par) {
    if(!ans.empty()) return;
    vis[node] = true; par[node] = p;
    for(auto x: g[node]) {
        if(x == p) continue;
        if(!vis[x]) dfs(x, node, g, vis, par);
        else {
            if(ans.empty()) {
                // only then modify otherwise keep on clearing every time tis piece of code hits but that would take a bit more time to execute
                // remove this if condition, and add ans.clear()
                int curr = node;
                ans.push_back(x);
                while(curr != x) {
                    ans.push_back(curr); curr = par[curr];
                }
                ans.push_back(x);
            }
        }
    }
}

void Main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0;i < m;i++) {
        int a, b;cin >> a >> b;
        a--, b-- ;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> vis(n, false);vector<int> par(n, -2);
    for(int i = 0;i < n;i++) {
        if(!vis[i]) {
            dfs(i, -1, g, vis, par);
            if(!ans.empty()) {
                cout << ans.size() << endl;
                for(auto x : ans) cout << x + 1 << " "; cout << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

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