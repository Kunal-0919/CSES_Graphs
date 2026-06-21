# Sum of distances in a Tree

```cpp []
class Solution {
public:
    vector<int> subtree, ans;
    void dfs(int node, int p, vector<vector<int>>&g, int d) {
        ans[0] += d;
        for(auto x : g[node]) {
            if(x == p) continue;
            dfs(x, node, g, d + 1);
            subtree[node] += subtree[x];
        }
    }
    void dfs2(int node, int p, vector<vector<int>>&g) {
        for(auto x : g[node]) {
            if(x == p) continue;
            ans[x] = ans[node] + g.size() - 2*subtree[x];
            dfs2(x, node, g);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto x : edges) {
            g[x[0]].push_back(x[1]); g[x[1]].push_back(x[0]);
        }
        ans.resize(n); subtree.resize(n);
        ans.assign(n, 0); subtree.assign(n,1);
        dfs(0, -1, g, 0); // now we have the ans for 0, but need to find the answer for each of the node, so we reroot
        dfs2(0, -1, g);
        return ans;
    }
};
```

Rerooting and subtree size problem,


