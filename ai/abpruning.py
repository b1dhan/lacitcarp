# Alpha-Beta Pruning

def alphabeta(depth, node, alpha, beta, maximizing):
    # Leaf node values
    values = [3, 5, 6, 9, 1, 2, 0, -1]

    # Stop at leaf nodes
    if depth == 3:
        return values[node]

    if maximizing:
        value = float('-inf')

        for i in range(2):
            value = max(value, alphabeta(depth + 1, node * 2 + i, alpha, beta, False))
            alpha = max(alpha, value)

            if beta <= alpha:
                break      # Prune

        return value

    else:
        value = float('inf')

        for i in range(2):
            value = min(value, alphabeta(depth + 1, node * 2 + i, alpha, beta, True))
            beta = min(beta, value)

            if beta <= alpha:
                break      # Prune

        return value

result = alphabeta(0, 0, float('-inf'), float('inf'), True)

print("Optimal Value:", result)