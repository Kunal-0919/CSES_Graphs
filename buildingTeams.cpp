#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll MOD = 1e9 + 7;
const ll INF = 9223372036854775807;
#define FAST_EXECUTION
#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

void Main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0;i < m;i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> p(n, -1);
    for(int i = 0;i < n;i++) {
        if(p[i] == -1) {
            // run bfs and mark everyone as 0 or 1
            queue<int> q; q.push(i); p[i] = 0;
            while(!q.empty()) {
                int curr = q.front(); q.pop();
                for(auto x : g[curr]) {
                    if(p[x] == -1) {
                        q.push(x); p[x] = 1 - p[curr];
                    } else {
                        if(p[curr] == p[x]) {
                            cout << "IMPOSSIBLE" << endl;
                            return;
                        }
                    }
                }
            }
        }
    }

    for(auto x : p) cout << x + 1 << " ";
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