# Rerooting in Trees

> Rerooting a Tree DP technique where we first solve the problem for a fixed root of the tree generally 0, and then efficiently move the root to all other nodes as if they were the roots.

Instead of recomputing the answer from scratch for every node, you reuse the answer of the parent to calculate the answer of the child.

```txt []
I know the answer when the tree is rooted at parent.
Can I use that to calculate the answer when the tree is rooted at child?
```

### Why do we need rerooting???

Suppose if a problem asks
```txt []
Find answer for every node as if that node were the root.
```

A brute force approach will be to run DFS/BFS for every node. `O(n^2)`

We can convert this to `O(n)` using rerooting, which typically includes 2 DFS traversals.

Rerooting Pattern: 
DFS 1: collect subtree information
```txt []
Root the tree at 0.
```

Calculate information from child to parent. Example:
```cpp []
subtreeSize[node] // subtree size for each node.
dp[node] // ans for node 0 would be

void dfs1(int node, int parent) {
    subtreeSize[node] = 1;
    // ans[node] = base_case
    for (int child : graph[node]) {
        if (child == parent) continue;

        dfs1(child, node);

        subtreeSize[node] += subtreeSize[child];
    }
}
```

DFS 2: Reroot from parent to child

DFS 2: reroot from parent to child
Now use the parent’s answer to calculate the child’s answer.
This DFS usually goes top-down.

```cpp []
void dfs2(int node, int parent) {
    for (int child : graph[node]) {
        if (child == parent) continue;

        dp[child] = transition(dp[node], child);

        dfs2(child, node);
    }
}
```

