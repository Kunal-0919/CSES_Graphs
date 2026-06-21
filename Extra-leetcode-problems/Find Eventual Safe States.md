# Find Eventual Safe States

```cpp []
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> in(n);
        vector<vector<int>> g(n);
        for(int i = 0;i < n;i++) {
            for(auto x : graph[i]) {
                g[x].push_back(i);
                in[i]++;
            }
        }
        queue<int> q;
        for(int i = 0;i < n;i++) {
            if(in[i]) continue;
            q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int curr = q.front();q.pop();
            res.push_back(curr);
            for(auto x: g[curr]) {
                in[x]--;
                if(in[x]) continue;
                q.push(x);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```

Reverse the graph and topo sort, the nodes inside the topo array will be the answer...