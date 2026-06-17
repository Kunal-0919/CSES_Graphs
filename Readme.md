# CSES - Graph Algorithms

## Counting Rooms
A simple number of connected components problem, can be done using DFS or BFS.

### DFS:
```cpp []
void dfs(int i, int j, vector<string> &g, vector<vector<bool>> &vis, int n, int m) {
    vis[i][j] = true;
    for(auto x : dir) {
        int nx = i + x[0], ny = j + x[1];
        if(nx < n && nx >= 0 && ny < m && ny >= 0 
        && g[nx][ny] == '.' && !vis[nx][ny])
        dfs(nx, ny, g, vis, n, m);
    }
}
```
## Labyrinth
For this we need to find the shortest distance from source to destination, along with the path followed, this can be done using BFS and DFS, but DFS would include many more computations that'll not be an optimal solution, BFS works well when edge weights are all the same(1 in this case). So, for this we simply initialise three things: visited array[n][m], path array[n][m]

1. visited array stores if this current cell has been visited
2. path array stores 'L' or 'R' or 'U' or 'D' to predict where it came from, if the value at the current cell equals L means it took Left turn from the last cell to reach here, so when we try to build the path back to the origin we can use this array. And for that if the current cell marks as L then backtrack to R.

```cpp []
vector<vector<int>> d(n, vector<int>(m, INT_MAX));
vector<vector<char>> par(n, vector<char>(m));
vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> dir_char = {'L', 'R', 'U', 'D'};
```

```cpp []
while(!q.empty()) {
    pair<int, int> curr = q.front(); q.pop();
    if(g[curr.first][curr.second] == 'B') { // in case we have found the destination
        cout << "YES" << endl;
        cout << d[curr.first][curr.second] << endl;
        string path;
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
      // for all directions check if we are making a valid move, 
      // and if valid move there, and add the path to it and mark it
      // as visited
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
```
## Building Roads
A simple connected components question:

1. Traverse through all the nodes.
    1. if node not visited
        1. store the node inside some array
        2. perform DFS


2. If array.size() <= 1 that means we dont need any extra road to make all the other connected components reachable, they already are in case == 1 and no nodes exist in case 0.
3. in that case, output all nodes in pair: (i, i + 1) or (0, i) where i > 0 to n - 1.

```cpp []
for(int i = 0;i < n;i++) {
    if(!vis[i]) {
        dfs(i, g, vis);
        par.push_back(i);
    }
}
if(par.size() == 1) {
    cout << 0 << endl;
} 
else {
    cout << par.size() - 1 << endl;
    for(int i = 1;i < par.size();i++) {
        cout << par[0] + 1 << " " << par[i] + 1 << endl;
    }
}
```
## Message Routes
Shortest path algorithm with same edge weights: we can perform BFS

## Building Teams
Bipartite Graph problem, can be solved using BFS.

### Algorithm
1. Initialise a color array which stores either 0 or 1(initialise to -1 so that we won't need another visited array to mark if the node is visited)
2. initialise a queue that stores the current node being traversed, mark the initial node's colour as 0. Do this for all components
3. for all the neighbours of the current node, check if it is already coloured or not
    1. in case it is already coloured to a different colour, from the one that it should be, then it is impossible to divide the nodes into two groups.
    2. else mark it as 1 - color[curr_node]

```cpp []
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
```
## Round Trip
Check if a cycle exists inside the current graph and print the cycle.

The graph is undirected, so we can simply do this using a visited array to see if the node is already visited and parent array to store the parent node which was visited before visiting the current node.

Can be done using DFS.

### Code:
```cpp []
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
```
## Monsters
Can be done using Multisource BFS, include all the monsters and create a distance array for monsters and one for us. These distance array stores the minimum distances to all the valid paths.

```cpp []
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
```
## Shortest Routes I
A simple implementation of Djikstra's algorithm over a directed graph.

```cpp []
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
vector<ll> dist(n, INF);
dist[0] = 0;
q.push({0, 0});
while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (d != dist[u]) continue; // stale
    for (auto [v, wt] : g[u]) {
        if (dist[v] > d + wt) {
            dist[v] = d + wt;
            q.push({dist[v], v});
        }
    }
}
for (auto x : dist) cout << x << " "; 
cout << endl;
```
## Shortest Routes II
Multi-source Shortest Path Algorithm. Floyd-Warshall Algorithm

```
vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
while (m--)
{
    ll u, v, w;
    cin >> u >> v >> w;
    dist[u][v] = min(dist[u][v], w);
    dist[v][u] = min(dist[v][u], w);
}
for (ll i = 1; i <= n; i++)
    dist[i][i] = 0;
for (ll k = 1; k <= n; k++)
{
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if ((dist[i][k] != LLONG_MAX) && (dist[k][j] != LLONG_MAX))
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}
```
## Flight Discount
Multi-state Djikstra's algorithm

```cpp []
priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
q.push({0, 0, 0});
vector<vector<ll>> dist(n, vector<ll>(2, LLONG_MAX));
dist[0][0] = 0, dist[0][1] = 0;

while(!q.empty()) {
    vector<ll> top = q.top();q.pop();
    ll d = top[0], used = top[1], curr = top[2];
    if(d > dist[curr][used]) continue; // stale values inside the heap
    for(auto [v, w] : g[curr]) {
        if(used) {
            if(dist[v][used] > w + d) {
                dist[v][used] = w + d;
                q.push({w + d, used, v});
            }
        } else {
            if(dist[v][used] > d + w) {
                dist[v][used] = d + w;
                q.push({d + w, used, v});
            }
            if(dist[v][used + 1] > d + w / 2) {
                dist[v][used + 1] = d + (w / 2);
                q.push({d + w / 2, used + 1, v});
            }
        }
    }
}

cout << min(dist[n - 1][0], dist[n - 1][1]) << endl;
```
## Cycle Finding
Finding a negative cycle inside a directed graph.

Use bellman ford algorithm to find the negative cycle, and store the last affected node in _Nth_ relaxation, that node will either be inside the negative cycle itself or it would be affected by the cycle.

If the last node is not present --> No negative cycle

Find the nth ancestor of that stored node --> that node will definitely be in the negative cycle.

Why n? cause there are n nodes and no more.

```cpp []
dist[0] = 0; ll last = -1;
for(ll i = 0;i < n;i++) {
    last = -1;
    for(auto edge : edges) {
        ll u = edge[0], v = edge[1], w = edge[2];
        if(dist[u] != LLONG_MAX && dist[v] > w + dist[u]) {
            dist[v] = dist[u] + w;
            last = v;
            par[v] = u;
        }
    }
}
if(last == -1) {
    cout << "NO" << endl;return;
}
for(ll i = 0;i < n;i++) last = par[last];
vector<ll> ans; ll node = last;
do {
    ans.push_back(node);
    node = par[node];
} while(last != node);
ans.push_back(node);
cout << "YES" << endl;
reverse(ans.begin(), ans.end());
for(auto x : ans) cout << x + 1 << " ";cout << endl;
```
## Flight Routes
Store all the distances of the nodes being visited inside a max heap.

```cpp []
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
q.push({0, 0});
vector<priority_queue<ll>> maxh(n); maxh[0].push(0);
while(!q.empty()) {
    pair<ll, ll> top = q.top();q.pop();
    ll d = top.first, curr = top.second;
    if(!maxh[curr].empty() && maxh[curr].top() < d) continue;
    for(auto [x, w] : g[curr]) 
    {
        if(maxh[x].size() < k || w + d < maxh[x].top()) {
            maxh[x].push(w + d);
            while(maxh[x].size() > k) maxh[x].pop();
            q.push({w + d, x});
        }
    }
}
ll i = 0;
vector<ll> ans(k);
while(!maxh[n - 1].empty()) {
    ans[i++] = maxh[n-1].top();maxh[n - 1].pop();
}
reverse(ans.begin(), ans.end());
for(auto x : ans) cout << x << " ";
cout << endl;
```
## Round Trip II
Finding a cycle but this time inside a directed graph. Can be done using DFS maintaining the state if the current node is already visited, but also inside the current DFS stack. if yes, then cycle exists, else cycle doesn't exist in the ones visited until now.

```cpp []
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
```
## Course Schedule
Topological Sort question. Kahn's algorithm

```cpp []
queue<ll> q;
for(ll i = 0;i < n;i++) {
    if(in[i]) continue;
    q.push(i);
}
vector<ll> ans;
while(!q.empty()) {
    ll curr = q.front();q.pop();
    ans.push_back(curr);
    for(auto x : g[curr]) {
        in[x]--;
        if(in[x])
        if(in[x]) continue;
        q.push(x);
    }
}
if(ans.size() != n) cout << "IMPOSSIBLE\n";
else {
    for(auto x : ans) cout << x + 1 << " ";
    cout << endl;
}
```
## Longest Flight Route
> Great Question

we can store topological order of the nodes, then use dist array initialised to LLONG_MIN, initialise distance of source node to 0.

then go through all the nodes in the topological order, and check if dist of the current node == LLONG_MIN, if yes continue; else go through all the neighbours of the current node in topological order and find maximum distance.

```cpp []
vector<ll> topo;
while(!q.empty()) {
    ll curr = q.front();q.pop();
    topo.push_back(curr);
    for(auto x : g[curr]) {
        in[x]--;
        if(in[x]) continue;
        q.push(x);
    }
}
vector<ll>dist(n, LLONG_MIN);dist[0] = 0;
vector<ll> par(n, -2); par[0] = -1;
for(ll curr : topo) {
    if(dist[curr] == LLONG_MIN) continue;
    // cout << curr << " " << dist[curr] << endl;
    for(auto x : g[curr]) {
        if(dist[curr] + 1 > dist[x]) {
            dist[x] = dist[curr] + 1;
            par[x] = curr;
        }
    }
}
```


## Game Routes
We need to find number of ways we can get to 1 to n in a DAG(topo sort???)

We topologically sort the nodes inside the graph. Then we can use DP on graphs to find the total number of ways.

> STATE

```
dp[n] = Number of ways to get to node n
```
> Transition

```
dp[neighbour] += dp[current_node]
```
```cpp []
vector<ll> dp(n);
dp[0] = 1;
for(auto x : topo) {
    for(auto v : g[x]) {
        dp[v] = (dp[x] + dp[v]) % MOD;
    }
}
```


## Investigations
what is the minimum price of such a route? --> DJIKSTRA

how many minimum-price routes are there? (modulo 1e9 + 7) -->  DP

what is the minimum number of flights in a minimum-price route? --> DP 

what is the maximum number of flights in a minimum-price route? --> DP

```
dist[n - 1], ways[n - 1], miniFlights[n - 1], maxiFlights[n - 1]
dist[0] = 0, ways[0] = 1, miniFlights[0] = 0, maxiFlights[0] = 0

MinHeap q;
q.push({0, 0});
while(!q.empty()) {
  ll d, u = q.top();q.pop();
  if(d != dist[u]) continue; // stale value
  
  for(auto [v, w] : g[u]) {
    if(w + d < dist[v]) {
      dist[v] = d + w;
      ways[v] = ways[u];
      miniFlights[v] = miniFlights[u] + 1;
      maxiFlights[v] = maxiFlights[u] + 1;
      q.push({{w + d, v}});
    } else if(w + d == dist[v]) {
      ways[v] += ways[u] % mod;
      miniFlights[v] = min(miniFlights[v], 1 + miniFligts[u]);
      maxiFlights[v] = max(maxiFlights[v], 1 + maxiFligts[u]);
    }
  }
}
```
```cpp []
vector<ll> dist(n, LLONG_MAX); dist[0] = 0;
vector<ll> ways(n, 0); ways[0] = 1;
vector<ll> miniFlights(n, LLONG_MAX);
vector<ll> maxiFlights(n, LLONG_MIN);
priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> q;
q.push({0, 0});
miniFlights[0] = 0;
maxiFlights[0] = 0;

while(!q.empty()) {
    pair<ll, ll> top = q.top();q.pop();
    ll d = top.first, curr = top.second;
    if(d != dist[curr]) continue;
    for(auto [v, w] : g[curr]) {
        ll newDist = dist[curr] + w;
        if(newDist < dist[v]) {
            dist[v] = newDist;
            ways[v] = ways[curr];
            miniFlights[v] = 1 + miniFlights[curr];
            maxiFlights[v] = 1 + maxiFlights[curr];
            q.push({newDist, v});
        } else if(newDist == dist[v]) {
            ways[v] = (ways[v] + ways[curr]) % MOD;
            miniFlights[v] = min(miniFlights[curr] + 1, miniFlights[v]);
            maxiFlights[v] = max(maxiFlights[curr] + 1, maxiFlights[v]);

        }
    }
}

```

Binary Lifting is a technique for answering "where i'll be after k jumps?"
very fast.

Instead of moving one step at a time, we precompute jumps of 1, 2, 4, 8, 16...

USACO guide describes this as precomputing the (2^k - 1) ancestor or 
successor, so later each query can be answered efficiently.

Suppose we want to move 13 steps backward, we can divide 13 into: 8 + 4 + 1

We have precomputed values of 8, 4, 1 step backward we can answer each query 
in O(1).
```