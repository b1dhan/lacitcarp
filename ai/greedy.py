from queue import PriorityQueue

# Graph with edge costs
graph = {
    'A': [('B', 2), ('C', 4)],
    'B': [('D', 3), ('E', 1)],
    'C': [('F', 5)],
    'D': [],
    'E': [('F', 2)],
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

def greedy_best_first(start, goal):
    visited = set()
    pq = PriorityQueue()

    pq.put((heuristic[start], start))

    print("Traversal:")

    while not pq.empty():
        h, node = pq.get()

        if node in visited:
            continue

        print(node, end=" ")
        visited.add(node)

        if node == goal:
            print("\nGoal Found!")
            return

        for neighbor, cost in graph[node]:
            if neighbor not in visited:
                pq.put((heuristic[neighbor], neighbor))

greedy_best_first('A', 'F')