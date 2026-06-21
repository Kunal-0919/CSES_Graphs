# Reorder Routes to Make All Paths Lead to the City Zero

```cpp []
class Solution {
public:
    int ans = 0;
    void dfs(int node, int p, vector<vector<pair<int, int>>> &g) {
        for(auto [v, i] : g[node]) {
            if(v == p) continue;
            ans += i;
            dfs(v, node, g);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> g(n);
        ans = 0;
        for(auto x : connections) {
            g[x[0]].push_back({x[1], 1});
            g[x[1]].push_back({x[0], 0});
        }
        dfs(0, -1, g);
        return ans;
    }
};
```