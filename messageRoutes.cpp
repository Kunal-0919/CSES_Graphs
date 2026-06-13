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
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0;i < m;i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> d(n, INT_MAX); vector<int> par(n,-1);
    queue<int> q;
    d[0] = 0; q.push(0);
    while(!q.empty()) {
        int curr = q.front();q.pop();
        if(curr == n - 1) {
            cout << d[n - 1] + 1 << endl;
            int idx = curr;
            vector<int> path;
            while(idx != -1) {
                path.push_back(idx);
                idx = par[idx];
            }
            reverse(path.begin(), path.end());
            for(auto x : path) cout << x + 1 << " ";
            cout << endl;
            return;
        }
        for(auto x : g[curr]) {
            if(d[x] == INT_MAX) {
                d[x] = 1 + d[curr]; par[x] = curr; q.push(x);
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