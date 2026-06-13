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
    vector<string> g(n);
    for(auto &x : g) {
        cin >> x;
    }
    int sx = -1, sy = -1, ex = -1, ey = -1;
    for(int i = 0;i <n ;i++) {
        auto s_idx = g[i].find('A');
        if(s_idx != string::npos) {
            sx = i, sy = s_idx;
        }
        auto e_idx = g[i].find('B');
        if(e_idx != string::npos) {
            ex = i, ey = e_idx;
        }
    }
    vector<vector<int>> d(n, vector<int>(m, INT_MAX));
    vector<vector<char>> par(n, vector<char>(m));
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<char> dir_char = {'L', 'R', 'U', 'D'};
    queue<pair<int, int>> q; q.push({sx, sy});
    d[sx][sy] = 0;

    while(!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        if(g[curr.first][curr.second] == 'B') {
            cout << "YES" << endl;
            cout << d[curr.first][curr.second] << endl;
            // logic for building the string
            string path;
            // for(auto x : par) {
            //     for(auto y : x) {
            //         if(y) cout << y << " ";
            //         else cout << "." << " ";
            //     }
            //     cout << endl;
            // }
            int i = ex, j = ey;
            while(par[i][j]) {
                // check the curr idx's parent value
                char parent_val = par[i][j];
                path += parent_val;
                if(parent_val == 'L') {
                    j += 1;
                } else if(parent_val == 'D') {
                    i -= 1;
                } else  if (parent_val == 'U') {
                    i += 1;
                } else {
                    j -= 1;
                }
            }
            reverse(path.begin(), path.end());
            cout << path << endl;
            return;
        }
        for(int i = 0;i < 4;i++) {
            vector<int> x = dirs[i];
            int nx = x[0] + curr.first, ny = x[1] + curr.second;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && d[nx][ny] == INT_MAX) {
                d[nx][ny] = 1 + d[curr.first][curr.second];
                par[nx][ny] = dir_char[i];
                q.push({nx, ny});
            }
        }
    }

    cout << "NO" << endl;

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