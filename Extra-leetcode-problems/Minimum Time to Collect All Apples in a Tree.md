# Minimum Time to Collect All Apples in a Tree

```cpp []
class Solution {
public:
    int dfs(int node, int p, vector<vector<int>>&g, vector<bool>&hasApple) {
        int time = 0;
        for(auto x : g[node]) {
            if(x == p) continue;
            int childTime = dfs(x, node, g, hasApple);
            if(childTime > 0 || hasApple[x]) {
                time += (2 + childTime);
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> g(n);
        for(auto x : edges) {
            g[x[0]].push_back(x[1]); g[x[1]].push_back(x[0]);
        }
        return dfs(0, -1, g, hasApple);
    }
};
```

Another simple DFS problem