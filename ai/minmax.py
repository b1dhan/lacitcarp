# MiniMax Algorithm

def minimax(depth, node, maximizing):
    # Leaf node values
    values = [3, 5, 6, 9, 1, 2, 0, -1]

    # Stop at leaf nodes
    if depth == 3:
        return values[node]

    if maximizing:
        return max(
            minimax(depth + 1, node * 2, False),
            minimax(depth + 1, node * 2 + 1, False)
        )
    else:
        return min(
            minimax(depth + 1, node * 2, True),
            minimax(depth + 1, node * 2 + 1, True)
        )

result = minimax(0, 0, True)

print("Optimal Value:", result)