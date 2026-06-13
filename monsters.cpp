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
    for (auto &row : g) cin >> row;
    const int INF = 1e9;

    vector<vector<int>> distA(n, vector<int>(m, INF));
    vector<vector<int>> distM(n, vector<int>(m, INF));
    vector<vector<char>> parent(n, vector<char>(m, 0));
    queue<pair<int,int>> qa, qm;
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'A') {
                sx = i;
                sy = j;
                qa.push({i, j});
                distA[i][j] = 0;
            } else if (g[i][j] == 'M') {
                qm.push({i, j});
                distM[i][j] = 0;
            }
        }
    }
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    char dc[4] = {'L', 'R', 'U', 'D'};
    while (!qm.empty()) {
        auto [x, y] = qm.front();
        qm.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                g[nx][ny] != '#' && distM[nx][ny] == INF) {
                distM[nx][ny] = distM[x][y] + 1;
                qm.push({nx, ny});
            }
        }
    }
    qa.push({sx, sy});
    while (!qa.empty()) {
        auto [x, y] = qa.front();
        qa.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                g[nx][ny] != '#' && distA[nx][ny] == INF) {

                int nd = distA[x][y] + 1;
                if (nd < distM[nx][ny]) {
                    distA[nx][ny] = nd;
                    parent[nx][ny] = dc[k];
                    qa.push({nx, ny});
                }
            }
        }
    }
    int ex = -1, ey = -1;
    for (int i = 0; i < n; i++) {
        if (distA[i][0] < distM[i][0]) {
            ex = i; ey = 0;
            break;
        }
        if (distA[i][m - 1] < distM[i][m - 1]) {
            ex = i; ey = m - 1;
            break;
        }
    }
    if (ex == -1) {
        for (int j = 0; j < m; j++) {
            if (distA[0][j] < distM[0][j]) {
                ex = 0; ey = j;
                break;
            }
            if (distA[n - 1][j] < distM[n - 1][j]) {
                ex = n - 1; ey = j;
                break;
            }
        }
    }
    if (ex == -1) {
        cout << "NO\n";
        return;
    }

    string path;
    int x = ex, y = ey;
    while (x != sx || y != sy) {
        char c = parent[x][y];
        path.push_back(c);
        if (c == 'L') y++;
        else if (c == 'R') y--;
        else if (c == 'U') x++;
        else if (c == 'D') x--;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';
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