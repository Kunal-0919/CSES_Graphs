from collections import deque
n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
indegree = [0] * (n + 1)
queue = deque([])
visited = [False] * (n + 1)
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1
 
for i in range(1,n + 1):
    if indegree[i] == 0:
        queue.append(i)
ans = []
while queue:
    curr = queue.popleft()
    visited[curr] = True
    ans.append(curr)
    indegree[curr] -= 1
    for neighbour in graph[curr]:
        indegree[neighbour] -= 1
        if indegree[neighbour] == 0:
            queue.append(neighbour)
 
visited[0] = True
if False in visited:
    print("IMPOSSIBLE")
else:
    for i in ans:
        print(i, end = " ")