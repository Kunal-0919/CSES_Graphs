# Minimum Edge Reversals so every Node is Reachable

```cpp []
class Solution {
public:
    vector<int> dp;
    void dfs1(int node, int p, vector<vector<pair<int, int>>>&g) {
        for(auto [x, i] : g[node]) {
            if(x == p) continue;
            dp[0] += 1 - i;
            dfs1(x, node, g);
        }
    }
    void dfs2(int node, int p, vector<vector<pair<int, int>>>&g) {
        for(auto [x, i] : g[node]) {
            if(x == p) continue;
            dp[x] = dp[node] + (i == 1 ? 1 : -1);
            dfs2(x, node, g);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        dp.resize(n); dp.assign(n, 0);
        for(auto x : edges) {
            g[x[0]].push_back({x[1], 1});
            g[x[1]].push_back({x[0], 0});
        }
        dfs1(0, -1, g);
        dfs2(0, -1, g);
        return dp;
    }
};
```

Rerooting problem, we can calculate the answer for 0, and then we run reroot dp with the transition as: 
dp[child] = dp[node] + (-1 in case of direction is 0 good when rooted at node but bad in the opposite case or +1 in case direction is 1, so it is good in case the value is rooted at node)
dp[child] = dp[node] + (i == 1 ? 1 : -1);