# Finish Time of Tasks I

```cpp []
class Solution {
public:
    long long dfs(int node, int p, vector<vector<int>>&g, vector<int>&baseTime) {
        bool isLeaf = true;
        long long latest = LLONG_MIN, earliest = LLONG_MAX;
        for(auto x : g[node]) {
            if(x == p) continue; // since its an undirected graph approach and a tree as well, no matter u can use 
            isLeaf = false;
            long long childCost = dfs(x, node, g, baseTime);
            latest = max(latest, childCost), earliest = min(earliest, childCost);
        }
        if(isLeaf) return (long long)baseTime[node];
        long long time = (latest - earliest) + baseTime[node];
        return latest + time;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> g(n);
        for(auto x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        return dfs(0, -1, g, baseTime);
    }
};
```

A simple DFS problem where in case a leaf node return the `baseTime for that node`, and in case not a leaf node: `ownTime + latest` time from child nodes, where `ownTime = (latest - earliest) + baseTime[node]`
```
dfs(int node, int p) {
    bool isLeaf = true;
    ll l = LLONG_MIN, r = LLONG_MAX;
    for(auto x : g[node]) {
        if(x == p) continue; 
        isLeaf = false;
        ll childCost = dfs(x, node);
        l = max(l, childCost), r = min(r, childCost);
    }
    ll ownTime = (l - r) + baseTime[node];
    return l + ownTime;
}
```