# Number of Ways to Arrive at Destination

```cpp []
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> g(n);
        for(auto x : roads) {
            g[x[0]].push_back({x[1], x[2]});
            g[x[1]].push_back({x[0], x[2]});
        }
        long long MOD = 1e9 + 7;
        vector<long long> dist(n, LLONG_MAX); vector<int>ways(n, 0);
        dist[0] = 0, ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto [d, u] = q.top();q.pop();
            if(d != dist[u]) continue;
            for(auto [v, w] : g[u]) {
                long long newDist = w + d;
                if(newDist < dist[v]) {
                    dist[v] = d + w;
                    q.push({d + w, v});
                    ways[v] = ways[u];
                } else if(newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
```