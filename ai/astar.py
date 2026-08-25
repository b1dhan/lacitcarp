from queue import PriorityQueue

# Graph with edge costs
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('D', 2), ('E', 5)],
    'C': [('F', 3)],
    'D': [],
    'E': [('F', 1)],
    'F': []
}

# Heuristic values
heuristic = {
    'A': 6,
    'B': 4,
    'C': 2,
    'D': 3,
    'E': 1,
    'F': 0
}

def astar(start, goal):
    pq = PriorityQueue()
    pq.put((0, start))

    cost = {start: 0}
    parent = {start: None}

    while not pq.empty():
        f, node = pq.get()

        if node == goal:
            break

        for neighbor, edge_cost in graph[node]:
            new_cost = cost[node] + edge_cost

            if neighbor not in cost or new_cost < cost[neighbor]:
                cost[neighbor] = new_cost
                priority = new_cost + heuristic[neighbor]
                pq.put((priority, neighbor))
                parent[neighbor] = node

    # Display path
    path = []
    node = goal
    while node is not None:
        path.append(node)
        node = parent[node]

    path.reverse()

    print("Shortest Path:", " -> ".join(path))
    print("Total Cost:", cost[goal])

astar('A', 'F')