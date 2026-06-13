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
        int s_idx = g[i].find('A');
        if(s_idx != string::npos) {
            sx = i, sy = s_idx;
        }
        int e_idx = g[i].find('B');
        if(e_idx != string::npos) {
            ex = i, ey = e_idx;
        }
    }

    // we can store the string inside the queue itself
    queue<pair<pair<int, int>, string>> q;
    vector<vector<int>> d(n, vector<int>(m, INT_MAX));
    d[sx][sy] = 0;
    q.push({{sx, sy}, ""});
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<char> dir_char = {'L', 'R', 'U', 'D'};
    while(!q.empty()) {
        pair<int, int> curr_idx = q.front().first;
        string path_till_now = q.front().second;
        q.pop();
        if(g[curr_idx.first][curr_idx.second] == 'B') {
            cout << "YES" << endl;
            cout << d[curr_idx.first][curr_idx.second] << endl;
            cout << path_till_now << endl;
            return;
        }
        for(int i = 0;i < 4;i++) {
            vector<int> x = directions[i];
            int nx = x[0] + curr_idx.first, ny = x[1] + curr_idx.second;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] != '#' && d[nx][ny] == INT_MAX) {
                d[nx][ny] = d[curr_idx.first][curr_idx.second] + 1;
                q.push({{nx, ny}, path_till_now + dir_char[i]});
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