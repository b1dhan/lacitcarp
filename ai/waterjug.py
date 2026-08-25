from collections import deque

def water_jug():
    visited = set()
    queue = deque([((0, 0), [])])  # (Jug1, Jug2), Path

    while queue:
        (a, b), path = queue.popleft()

        if (a, b) in visited:
            continue

        visited.add((a, b))
        path = path + [(a, b)]

        # Goal: Get 2 liters
        if a == 2 or b == 2:
            print("Solution Path:")
            for state in path:
                print(state)
            return

        # Possible operations
        next_states = [
            (4, b),                        # Fill Jug1
            (a, 3),                        # Fill Jug2
            (0, b),                        # Empty Jug1
            (a, 0),                        # Empty Jug2
            (max(0, a - (3 - b)), min(3, a + b)),  # Pour Jug1 -> Jug2
            (min(4, a + b), max(0, b - (4 - a)))   # Pour Jug2 -> Jug1
        ]

        for state in next_states:
            if state not in visited:
                queue.append((state, path))

water_jug()