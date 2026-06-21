# Number of Nodes in the Sub-Tree With the Same Label

```cpp []
class Solution {
public:
    void dfs(int node, int p, vector<vector<int>> &g, vector<vector<int>>&subtree, string labels) {
        char label = labels[node];
        subtree[node][label - 'a'] = 1;
        for(auto x: g[node]) {
            if(x == p) continue;
            dfs(x, node, g, subtree, labels);
            for(int i = 0;i < 26;i++) {
                subtree[node][i] += subtree[x][i];
            }
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for(auto x : edges) {
            g[x[0]].push_back(x[1]); g[x[1]].push_back(x[0]);
        }
        vector<vector<int>> subtree(n, vector<int>(26));
        dfs(0, -1, g, subtree, labels);
        vector<int> res(n);
        for(int i = 0;i < n;i++) {
            res[i] = subtree[i][labels[i] - 'a'];
        }
        return res;
    }
};
```

Another simple DFS problem