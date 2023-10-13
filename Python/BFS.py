from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])

    while queue:
        node = queue.popleft()
        if node not in visited:
            print(node, end=' ')
            visited.add(node)
            queue.extend(neighbour for neighbour in graph.get(node, []) if neighbour not in visited)

# Get user input for the graph
graph = {}
while True:
    node = input("Enter a node (or press Enter to finish): ")
    if not node:
        break
    neighbors = input("Enter neighbors of {}: ".format(node)).split()
    graph[node] = neighbors

start_node = input("Enter the starting node for BFS: ")

if start_node in graph:
    print("BFS traversal starting from node", start_node, ":")
    bfs(graph, start_node)
else:
    print("Starting node not found in the graph.")
