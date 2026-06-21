# Minimum Fuel Cost to Report to the Capital
```cpp []
class Solution {
public:
    long long ans;
    int dfs(int node, int p, vector<vector<int>> &g, int seats) {
        int cnt = 1;
        for(auto x : g[node]) {
            if(x == p) continue;
            cnt += dfs(x, node, g, seats);
        }
        if(node == 0) return 0;
        ans += (cnt + seats - 1) / seats;
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> g(n); ans = 0;
        for(auto x : roads) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        dfs(0, -1, g, seats);
        return ans;
    }
};
```

DFS traversal problem, for a tree, the answer depends on the size of the subtree.
time taken till that subnode = sizesubtree + seats - 1 / seats