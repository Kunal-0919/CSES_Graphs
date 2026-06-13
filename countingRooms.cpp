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


vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j, vector<string> &g, vector<vector<bool>> &vis, int n, int m) {
    vis[i][j] = true;
    for(auto x : dir) {
        int nx = i + x[0], ny = j + x[1];
        if(nx < n && nx >= 0 && ny < m && ny >= 0 && g[nx][ny] == '.' && !vis[nx][ny])
        dfs(nx, ny, g, vis, n, m);
    }
}

void Main() {
    int n, m;cin >> n >> m;
    vector<string> g(n);
    for(int i = 0;i < n;i++) {
        cin >> g[i];
    }

    // for(auto x : g) cout << x << endl;
    int ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m));

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(!vis[i][j] && g[i][j] == '.') {
                dfs(i, j, g, vis, n, m);
                ans++;
            }
        }
    }

    cout << ans << endl;
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